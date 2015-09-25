#include <Boss.h>

Boss::Boss()
{

}

void Boss::initialize()
{
	animation.setSpriteSheet("Boss_Head.png");
	animation.addFrame(sf::IntRect(0,0,animation.spriteSheet.getSize().x,animation.spriteSheet.getSize().y));
	animation.setSpeed(0.f);
	setAnimation(animation);
	play();
	setPosition(320.f,100.f);

	setHealth(1000);
}

void Boss::update() 
{
	animate();
}
