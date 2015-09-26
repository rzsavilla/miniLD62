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

	setSpeed(50.f);
	setHealth(100);
	iLives = 3;
	fMoveDist = 32;
	//Starting Position
	setPosition((screenSize.x / 2) + 16, screenSize.y - ((getTextureRect().height)* 2) - 48);
	bJustMoved = false;
	setMoveDelay(0.5f);				//Delay time before player can move again;
}

void Player::update(InputHandler& input, sf::Time dt)
{
	animate();						//Update Animation
	playerInputs(input, dt);			//Check inputs
}

int Player::getLives()
{
	return iLives;
}

void Player::setMoveDelay(float Delay)
{
	fMoveDelay = Delay;
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
	//std::cout << velocity.y << std::endl;
	if (bJustMoved) {
		if (moveTimer.getElapsedTime().asSeconds() > fMoveDelay) {
			bJustMoved = false;
			moveTimer.restart();
		}
	}

	//Shoot Projectile;
	if (input.bSpace) {

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