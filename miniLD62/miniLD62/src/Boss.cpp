#include <Boss.h>

Boss::Boss()
{
}

void Boss::initialize()
{
	animation.setSpriteSheet("Spritesheet_Boss.png");
	animation.addFrame(sf::IntRect(0,0,64,75));
	animation.addFrame(sf::IntRect(64,0,64,75));
	animation.setSpeed(0.3f);
	setAnimation(animation);
	setPosition(320.f,150.f);
	setHealth(1000);
	setScale(2,2);
	play();
	loopAnimation(false);
}

void Boss::update(sf::Vector2f playerPos) 
{
	//Animation
	animate();
	//reset();		//reset Animation

	if (isFinished()) {
		setFrame(0);
	}

	//Movement/Rotation

	/*
	//Rotate to face the target
	float dx = playerPos.x - getPosition().x;
	float dy = playerPos.y - getPosition().y;
	const float Pi = 3.141;

	//std::cout << "POSX: " << dx << std::endl;
	setRotation(atan2(dy,dx) * (180 / Pi) - 90);
	*/
}
