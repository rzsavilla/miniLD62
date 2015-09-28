#include <Player.h>
#include <cmath>		//Pythagoras

Player::Player()
{

}

void Player::initialize(sf::Vector2u screenSize)
{
	//Animation
		//load/set Animations	

	spriteSheet.loadFromFile("assets/textures/villager.png");
	idleAnimation.setSpriteSheet(spriteSheet);
	idleAnimation.addFrames(sf::IntRect(0,0,32,32),2,spriteSheet.getSize());
	idleAnimation.setSpeed(0.5f);
	movingUp.setSpriteSheet(spriteSheet);
	movingDown.setSpriteSheet(spriteSheet);
	movingLeft.setSpriteSheet(spriteSheet);
	movingRight.setSpriteSheet(spriteSheet);
	movingUp.addFrames(sf::IntRect(0,64,32,32),2,spriteSheet.getSize());
	movingDown.addFrames(sf::IntRect(0,32,32,32),2,spriteSheet.getSize());
	movingLeft.addFrames(sf::IntRect(0,96,32,32),2,spriteSheet.getSize());
	movingRight.addFrames(sf::IntRect(0,128,32,32),2,spriteSheet.getSize());
	movingUp.setSpeed(0.2f);
	movingDown.setSpeed(0.2f);
	movingLeft.setSpeed(0.2f);
	movingRight.setSpeed(0.2f);
	loopAnimation(true);
	setAnimation(movingUp);

	setHealth(1000);
	setSpeed(90.f);
	setFireRate(0.5f);
	fMoveDist = 32;
	iMaxMana = 100;
	iMana = 100;
	//Starting Position
	startPos = sf::Vector2f((screenSize.x / 2) + 16, screenSize.y - ((getTextureRect().height)* 2) - 48);
	setPosition(startPos);
	bJustMoved = false;
	setMoveDelay(0.5f);				//Delay time before player can move again;
	direction = MyEnum::Up;
}

void Player::update(InputHandler& input, sf::Time dt)
{
	animate();						//Update Animation
	playerInputs(input, dt);			//Check input
	float fSpellCost = 10;
	
	if (iMana < 0) {
		iMana = 0;
	} else if (iMana > iMaxMana) {
		iMana = iMaxMana;
	}

	//Regenerate Mana over time
	if (iMana < iMaxMana) {
		
		if (manaRegen.getElapsedTime().asSeconds() > 0.5f) {
			iMana += 1;
			manaRegen.restart();
		}
	}

	//Check if Spell can be cast

	if (weaponTimer.getElapsedTime().asSeconds() > fFireRate) {
		if (iMana >= fSpellCost) {	//Player has enough mana
			weaponTimer.restart();
			bCanShoot = true;
		} else {
			bCanShoot = false;		//Player does not have enough mana
		}	
	}
}

void Player::resetPosition()
{
	setPosition(startPos);
}

float Player::getRateOfFire() 
{
	return fFireRate;
}

void Player::setMoveDelay(float Delay)
{
	fMoveDelay = Delay;
}

void Player::setFireRate(float Rate)
{
	fFireRate = Rate;
}

void Player::setMana(int Mana)
{
	iMana = Mana;
}

void Player::addMana(int i)
{
	iMana += i;
}

void Player::useMana(int i)
{
	iMana -= i;
}

int Player::getMana()
{
	return iMana;
}

void Player::playerInputs(InputHandler& input, sf::Time dt)
{
	//Change Velocity/Move
	if (input.bUp) {
		moveUp();
		setAnimation(movingUp);
		bJustMoved = true;
	} else if (input.bDown) {
		moveDown();
		setAnimation(movingDown);
		bJustMoved = true;
	} else if (input.bLeft) {
		moveLeft();
		setAnimation(movingLeft);
		bJustMoved = true;
	} else if (input.bRight) {
		moveRight();
		setAnimation(movingRight);
		bJustMoved = true;
	}
	if (bJustMoved) {
		moveTimer.restart();
	} else {

	}
	input.bUp = false, input.bDown = false; 
	input.bLeft = false, input.bRight = false;

	updateMovement(dt);
	if (bJustMoved) {
		if (moveTimer.getElapsedTime().asSeconds() > fMoveDelay) {
			bJustMoved = false;
			moveTimer.restart();
		}
	}
}

void Player::calcNewPos()
{
	targetpos = sf::Vector2f(getPosition().x, getPosition().y);	//set to current position
	switch (direction)
	{
		//Calculate Target position 
	case MyEnum::Up:
		targetpos.y -= fMoveDist;
		break;
	case MyEnum::Down:
		targetpos.y += fMoveDist;
		break;
	case MyEnum::Left:
		targetpos.x -= fMoveDist;
		break;
	case MyEnum::Right:
		targetpos.x += fMoveDist;
		break;
	default:
		break;
	}
}

void Player::moveUp()
{
	resetVelocity();
	velocity.y = -getSpeed();
	direction = MyEnum::Direction::Up;
}

void Player::moveDown()
{
	resetVelocity();
	velocity.y = getSpeed();
	direction = MyEnum::Direction::Down;
}

void Player::moveLeft()
{
	resetVelocity();
	velocity.x = -getSpeed();
	direction = MyEnum::Direction::Left;
}

void Player::moveRight()
{
	resetVelocity();
	velocity.x = getSpeed();
	direction = MyEnum::Direction::Right;
}

void Player::updateMovement(sf::Time dt) 
{
	if (isMoving()) {

		switch (direction)
		{
		case MyEnum::Up:
			setAnimation(movingUp);
			break;
		case MyEnum::Down:
			setAnimation(movingDown);
			break;
		case MyEnum::Left:
			setAnimation(movingLeft);
			break;
		case MyEnum::Right:
			setAnimation(movingRight);
			break;
		default:
			break;
		}
		play();			//Animation
		//Calculate distance from target position
			//Pythagoras
		//Move
		move(velocity * dt.asSeconds());
		
	} else {
		stop();				//Stop animation when animation finishes playing;
	}
}