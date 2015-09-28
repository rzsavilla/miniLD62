#include <PlayScreen.h>
#include <iostream>
PlayScreen::PlayScreen()
{

}
 
void PlayScreen::initialize(sf::Vector2u windowSize, Resources_Text& resources)
{
	//Player
	player.initialize(windowSize);
	//Boss
	boss.initialize();
	boss.setHealth(10000);

	//Grid
	gridTexture.loadFromFile("assets/textures/Grid_Background.png");
	grid.setTexture(gridTexture);

	//HUD - Head Up Display
	hud.initialize(windowSize, resources);
	hud.setBossHealth(boss.getHealth());
	hud.setHealth(player.iHealth);
	hud.setMana(player.getMana());

	rock_Animation.setSpriteSheet("Projectile.png");
	rock_Animation.addFrame(sf::IntRect(0,0,4,16));
	fireball.setSpeed(100.f);
	//fireball.setTargetPos(boss.getPosition());
	fireball.setAnimation(rock_Animation);

	bullet_Explode.setSpriteSheet("Projectile_Explosion.png");
	bullet_Explode.addFrames(sf::IntRect(0,0,32,23),4,bullet_Explode.spriteSheet.getSize());
	bullet_Explode.setSpeed(0.1f);
	fireball.setAnimation(bullet_Explode);
	fireball.loopAnimation(false);
	playerProj.setProjectile(fireball);

	bossProj.setProjectile(fireball);

	float fSizeW = 480.f;
	float fSizeH = 220.f;
	safeZone = sf::FloatRect((windowSize.x / 2) - (fSizeW / 2),windowSize.y - fSizeH, fSizeW, fSizeH);

	//shape.setFillColor(sf::Color::White);
	//shape.setSize(sf::Vector2f(500.f,250.f));
	//shape.setPosition();
	//shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);

	//Wall
	float fOffset = 5.f;
	topBB = sf::FloatRect(0,0,windowSize.x,fOffset);
	botBB = sf::FloatRect(0,windowSize.y - fOffset, windowSize.x, fOffset);
	lefBB = sf::FloatRect(0,0,fOffset,windowSize.y);
	rigBB = sf::FloatRect(windowSize.x - fOffset, 0,fOffset, windowSize.y);

	//Pickups
	Animation_Mana_Pickup.setSpriteSheet("Mana_Pickup_Spritesheet.png");
	Animation_Mana_Pickup.addFrames(sf::IntRect(0,0,32,32),4, Animation_Mana_Pickup.spriteSheet.getSize());
	Animation_Mana_Pickup.setSpeed(0.2f);
	Pickup_Mana.setAnimation(Animation_Mana_Pickup);
	Pickup_Mana.setDuration(5.f);
	Pickup_Mana.loopAnimation(true);
	Pickup_Mana.play();


	srand(time(NULL));	//Random Seed

	window = windowSize;

	//Boss Skills
	bNormal = false;
	bAssault = false;
}

MyEnum::State PlayScreen::update(InputHandler& input, sf::Time dt)
{
	MyEnum::State currentState = MyEnum::State::Play;
	
	//hud.setHealth(player.getHealth());
	hud.updateBossHealth(boss.getHealth());
	hud.updatePlayerHealth(player.iHealth);
	hud.updatePlayerMana(player.getMana());

	//Player
	player.update(input, dt);
	boss.update(player.getPosition());
	//Projectiles
	updatePlayerProj(input, dt);
	updateBossProj(input,dt);
	//Collision
		//Player
	if (!safeZone.intersects(player.getGlobalBounds())) {
		//Take Damage
		if (damageTimer.getElapsedTime().asSeconds() > 0.3f) {
			player.damage(1);
			player.setColor(sf::Color::Red);
			damageTimer.restart();
		}
	} else {
		player.setColor(sf::Color::White);
	}

	if (player.getGlobalBounds().intersects(boss.getGlobalBounds())) {
		player.resetPosition();
		player.damage(50);
	} else if (player.getGlobalBounds().intersects(topBB)) {
		player.moveDown();
	} else if (player.getGlobalBounds().intersects(botBB)) {
		player.moveUp();
	} else if (player.getGlobalBounds().intersects(lefBB)) {
		player.moveRight();
	} else if (player.getGlobalBounds().intersects(rigBB)) {
		player.moveLeft();
	}
	
	//Pickups
	updatePickups(window);
	
	//Game Over Check
	if (player.getHealth() <= 0) {
		currentState = MyEnum::State::GameOver;
	}

	//Victory Check
	if (boss.getHealth() <= 0) {
		currentState = MyEnum::State::GameOver;
	} else if (player.getHealth() <= 0) {
		currentState = MyEnum::State::GameOver;
	}

	return currentState;
}

void PlayScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	target.draw(grid,states);
	target.draw(pickups,states);
	target.draw(player,states);
	target.draw(boss,states);
	target.draw(hud, states);
	//target.draw(shape, states);

	target.draw(playerProj, states);
	target.draw(bossProj, states);
	
}

void PlayScreen::updatePlayerProj(InputHandler& input, sf::Time dt)
{
	playerProj.updateProjectiles(dt);

	if (input.bSpace) {
		if (player.bCanShoot) {
			playerProj.Shoot(player.getPosition(),player.getDirection(),fireball.getSpeed());
			player.useMana(10.f);
			input.bSpace = false;
			player.bCanShoot = false;
		}
	}
	//Collision
	float bossWidth = boss.getGlobalBounds().width;
	float bossHeight = boss.getGlobalBounds().height;
	sf::Vector2f bossPos = boss.getPosition();
	bossCollRect = sf::FloatRect(bossPos.x - (bossWidth / 4), bossPos.y - (bossHeight / 4), bossWidth / 2,bossHeight / 2);

	for (int i = 0; i <  playerProj.projectiles.size(); i++) {
		bool bCollision = false;

		if (playerProj.projectiles[i].getGlobalBounds().intersects(bossCollRect)) {
			bCollision = true;
			if (!playerProj.projectiles[i].hasCollided()) {
				boss.damage(50.f);
			}
		} 
		if (playerProj.projectiles[i].getGlobalBounds().intersects(topBB)) {
			bCollision = true;
		} else if (playerProj.projectiles[i].getGlobalBounds().intersects(botBB)) {
			bCollision = true;
		} else if (playerProj.projectiles[i].getGlobalBounds().intersects(lefBB)) {
			bCollision = true;
		} else if (playerProj.projectiles[i].getGlobalBounds().intersects(rigBB)) {
			bCollision = true;
		}

		if (bCollision) {
			playerProj.projectiles[i].collided();
			playerProj.projectiles[i].setAnimation(bullet_Explode);
			playerProj.projectiles[i].setScale(2.f,2.f);
			playerProj.projectiles[i].play();
			playerProj.projectiles[i].resetVelocity();
		}

		playerProj.projectiles[i].animate();
	}
	//Destroy
	for (int i = 0 ; i < playerProj.projectiles.size(); i++) {
		if (playerProj.projectiles[i].hasCollided()) {
			if (!playerProj.projectiles[i].isPlaying()) {
				playerProj.projectiles[i].destroy();
			}
		}
	}
}

void PlayScreen::updateBossProj(InputHandler& input, sf::Time dt)
{
	bossProj.updateProjectiles(dt);
	if (bossTimer.getElapsedTime().asSeconds() > 2.f) {
		//Select Ability
		int i = rand() % 10 + 1; 
		if (i  <= 8) {
			bossProj.setProjectile(fireball);
			fireball.iDamage = 5;
			bNormal = true;
			fireball.setScale(1,1);
			attackTimer.restart();
			
		} else {
			fireball.iDamage = 10;
			fireball.setScale(2.5,2.5);
			bAssault = true;
		}

		bossTimer.restart();
	}

	if (bNormal) {
		boss.setFrame(1);
		if (attackTimer.getElapsedTime().asSeconds() > 0.5f) {
			for (int i = 0; i < 4; i++) {
				bossProj.Shoot(boss.getPosition(),player.getPosition());
				if (i > 4) {
					bNormal = false;
				}
				attackTimer.restart();
			}			
			
		}
	} else if (bAssault) {
		boss.setFrame(1);
		if (attackTimer.getElapsedTime().asSeconds() > 1.0f) {
			for (int i = 0; i <= 2; i++) {
				bossProj.Shoot(boss.getPosition(),player.getPosition());
				if (i > 2) {
					bAssault = false;
				}
				attackTimer.restart();
			}			
		}
	}

	//Check for Collisions
	if (bossProj.projCount() > 0) {
		for (int i = 0; i < bossProj.projectiles.size(); i++) {
			bool bCollision = false;
			//Collision with player
			if (bossProj.projectiles[i].getGlobalBounds().intersects(player.getGlobalBounds())) {
				bCollision = true;
				if (!bossProj.projectiles[i].hasCollided()) {
					player.iHealth -= fireball.iDamage;
				} 
			//Has Reached Target
			} else if (bossProj.projectiles[i].hasReachedTarget()) {
				bCollision = true;
			}

			if (bCollision) {
				bossProj.projectiles[i].resetVelocity();
				bossProj.projectiles[i].collided();
				bossProj.projectiles[i].play();
				bossProj.projectiles[i].setAnimation(bullet_Explode);
			}
			bossProj.projectiles[i].animate();
		}

		for (int i = 0 ; i < bossProj.projectiles.size(); i++) {
			bossProj.projectiles[i].animate();
		}
		//Destroy
		for (int i = 0 ; i < bossProj.projectiles.size(); i++) {
			if (bossProj.projectiles[i].hasCollided()) {
				if (!bossProj.projectiles[i].isPlaying()) {
					bossProj.projectiles[i].destroy();
				}
			}
		}
	}
}

void PlayScreen::updatePickups(sf::Vector2u windowSize)
{
	pickups.update();
	if (pickupTimer.getElapsedTime().asSeconds() > 10.f) {
		if (pickups.pickups.size() < 1) {
			//Generate Random Position
			float X = rand() % (window.x - 50) + 50;
			float Y = rand() % (int)(window.y - 50) + 100;
			if (Y >= 450) {
				Y = 450;
			} else if (Y <= 290) {
				Y = 300;
			}
			if (X > 550) {
				X = 550;
			} else if (X < 100) {
				X = 100;
			}
			pickups.spawn(Pickup_Mana,sf::Vector2f(X,Y));
			pickupTimer.restart();
		} else {
			pickups.pickups.erase(pickups.pickups.begin());
		}
	}
	//Player collects pickup
	for (int i = 0; i < pickups.pickups.size(); i++) {
		if (player.getGlobalBounds().intersects(pickups.pickups[i].getGlobalBounds())) {
			player.addMana(50);
			pickups.pickups.erase(pickups.pickups.begin() + i);
		}
	}/*
	//Erase Pickups that have expired
	for (int i = 0; i < pickups.pickups.size(); i++) {
		if (pickups.pickups[i].isDestroyed()) {
			pickups.pickups.erase(pickups.pickups.begin() + i);
		}
	}
	*/
}

