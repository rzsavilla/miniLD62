#include <Player.h>
#include <cmath>		//Pythagoras

Player::Player()
{

}

void Player::initialize(sf::Vector2u screenSize)
{
	//Animation
		//load/set Animations	
	moveAnimation.setSpriteSheet("player.png");
	moveAnimation.addFrames(sf::IntRect(0,0,32,32),3,moveAnimation.spriteSheet.getSize());
	moveAnimation.setSpeed(0.5f);
	loopAnimation(true);
	setAnimation(moveAnimation);
	play();							//Start Animation

	setSpeed(100.f);
	fMoveDist = 32;
	setPosition((screenSize.x / 2) + 16, screenSize.y - ((getTextureRect().height)* 2) + 16);
	bJustMoved = false;
	setMoveDelay(0.5f);				//Delay time before player can move again;
}

void Player::update(InputHandler& input, sf::Time dt)
{
	animate();						//Update Animation
	playerInputs(input, dt);			//Check inputs
}

void Player::setMoveDelay(float Delay)
{
	fMoveDelay = Delay;
}

void Player::playerInputs(InputHandler& input, sf::Time dt)
{
	if (!bJustMoved) {						//Move Delay
		if (!isMoving()) {
			//Change Velocity/Move
			if (input.bUp) {
				moveUp();
				bJustMoved = true;
			} else if (input.bDown) {
				moveDown();
				bJustMoved = true;
			} else if (input.bLeft) {
				moveLeft();
				bJustMoved = true;
			} else if (input.bRight) {
				moveRight();
				bJustMoved = true;
			}
			if (bJustMoved) {
				moveTimer.restart();
			}
			input.bUp = false, input.bDown = false; 
			input.bLeft = false, input.bRight = false;
		}
	}
	
	updateMovement(dt);
	//std::cout << velocity.y << std::endl;
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
	velocity.y = -getSpeed();
	direction = MyEnum::Direction::Up;
	calcNewPos();
}

void Player::moveDown()
{
	velocity.y = getSpeed();
	direction = MyEnum::Direction::Down;
	calcNewPos();
}

void Player::moveLeft()
{
	velocity.x = -getSpeed();
	direction = MyEnum::Direction::Left;
	calcNewPos();
}

void Player::moveRight()
{
	velocity.x = getSpeed();
	direction = MyEnum::Direction::Right;
	calcNewPos();
}

void Player::updateMovement(sf::Time dt) 
{
	if (isMoving()) {
		//Calculate distance from target position
			//Pythagoras
		
		float fDistance = sqrt((pow(targetpos.x - getPosition().x, 2) + (pow(targetpos.y - getPosition().y, 2))));
		
		if (fDistance < 5) {
			resetVelocity();
			setPosition(targetpos);
		}
		std::cout << fDistance << std::endl;
		//Move
		move(velocity * dt.asSeconds());
	}
}

