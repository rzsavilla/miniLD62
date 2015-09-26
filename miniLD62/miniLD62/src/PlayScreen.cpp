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

	rock_Animation.setSpriteSheet("Projectile.png");
	rock_Animation.addFrame(sf::IntRect(0,0,4,16));
	rock.setSpeed(100.f);
	rock.setTargetPos(boss.getPosition());
	rock.setAnimation(rock_Animation);

	bullet_Explode.setSpriteSheet("Projectile_Explosion.png");
	//bullet_Explode.addFrame(sf::IntRect(0,0,32,23));
	bullet_Explode.addFrames(sf::IntRect(0,0,32,23),4,bullet_Explode.spriteSheet.getSize());
	bullet_Explode.setSpeed(0.1f);
	rock.setAnimation(rock_Animation);
	rock.loopAnimation(false);
	bullets.setProjectile(rock);


	shape.setFillColor(sf::Color::White);
	shape.setSize(sf::Vector2f(100.f,100.f));
	shape.setPosition(100.f,100.f);
	shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
}

MyEnum::State PlayScreen::update(InputHandler& input, sf::Time dt)
{
	MyEnum::State currentState = MyEnum::State::Play;

	player.update(input, dt);
	boss.update(player.getPosition());
	hud.setHealth(player.getHealth());
	hud.setLives(player.getLives());
	hud.updateBossHealth(boss.getHealth());
	if (input.bSpace) {
		bullets.Shoot(player.getPosition(),boss.getPosition());
		input.bSpace = false;
	}

	//Projectiles
	bullets.updateProjectiles(dt);

	//Collision
	float bossWidth = boss.getGlobalBounds().width;
	float bossHeight = boss.getGlobalBounds().height;
	sf::Vector2f bossPos = boss.getPosition();
	sf::FloatRect bossCollRect(bossPos.x - (bossWidth / 4), bossPos.y - (bossHeight / 4), bossWidth / 2,bossHeight / 2);

	shape.setSize(sf::Vector2f(bossWidth / 2,bossHeight / 2));
	shape.setPosition(sf::Vector2f(bossPos.x, bossPos.y));
	shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
	for (int i = 0; i <  bullets.projectiles.size(); i++) {
		if (bullets.projectiles[i].getGlobalBounds().intersects(bossCollRect)) {
			if (!bullets.projectiles[i].hasCollided()) {
				boss.damage(100.f);
				bullets.projectiles[i].collided();
			}

			
			bullets.projectiles[i].setAnimation(bullet_Explode);
			bullets.projectiles[i].play();
			bullets.projectiles[i].setSpeed(10.f);
		}
		bullets.projectiles[i].animate();
	}

	for (int i = 0 ; i < bullets.projectiles.size(); i++) {
		if (bullets.projectiles[i].hasCollided()) {
			if (!bullets.projectiles[i].isPlaying()) {
				bullets.projectiles[i].destroy();
			}
		}
	}

	//Destroy
	for (int i = 0; i < bullets.projectiles.size(); i++) {
		if (bullets.projectiles[i].isDestroyed()) {
			bullets.projectiles.erase(bullets.projectiles.begin() + i);
		}
	}
	//Game Over Check
	if (player.getLives() <= 0) {
		std::cout << "Game Over\n";
		currentState = MyEnum::State::GameOver;
	}

	//Victory Check
	if (boss.getHealth() <= 0) {
		currentState = MyEnum::State::GameOver;
	}
	return currentState;
}

void PlayScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	target.draw(grid,states);
	target.draw(player,states);
	target.draw(boss,states);
	target.draw(hud, states);

	//target.draw(shape, states);
	target.draw(bullets, states);
	
}
