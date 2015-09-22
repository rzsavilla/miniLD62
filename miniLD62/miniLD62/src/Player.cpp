#include <Player.h>

Player::Player()
{

}

void Player::initialize(sf::Vector2u screenSize)
{
	

	//Animation
		//load/set Animations	
	moveAnimation.setSpriteSheet("player.png");
	moveAnimation.addFrames(sf::IntRect(0,0,32,32),3,moveAnimation.spriteSheet.getSize());
	moveAnimation.setSpeed(0.3f);
	loopAnimation(true);
	setAnimation(moveAnimation);
	play();							//Start Animation

	setSpeed(32);
	setPosition(screenSize.x / 2, screenSize.y - (getTextureRect().height * 2));
	bJustMoved = false;
	setMoveDelay(0.2f);				//Delay time before player can move again;
}

void Player::update(InputHandler& input)
{
	animate();						//Update Animation
	playerInputs(input);			//Check inputs
}

void Player::setMoveDelay(float Delay)
{
	fMoveDelay = Delay;
}

void Player::playerInputs(InputHandler& input)
{
	if (!bJustMoved) {
		//Player can move

		//Change Velocity/Move
		if (input.bUp) {
			moveUp();
			bJustMoved = true;
			input.bUp = false;
		} else if (input.bDown) {
			moveDown();
			bJustMoved = true;
			input.bDown = false;
		} else if (input.bLeft) {
			moveLeft();
			bJustMoved = true;
			input.bLeft = false;
		} else if (input.bRight) {
			moveRight();
			bJustMoved = true;
			input.bRight = false;
		}
		//New Position
		float posX = getPosition().x + getVelocity().x;
		float posY = getPosition().y + getVelocity().y;
		setPosition(posX,posY);
		resetVelocity();
	} else {
		//Player cannot move, wait for delay
		if (moveTimer.getElapsedTime().asSeconds() > fMoveDelay) {
			bJustMoved = false;
			moveTimer.restart();
		}
	}
}

