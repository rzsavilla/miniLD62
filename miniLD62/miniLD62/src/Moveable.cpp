#include <Moveable.h>

Moveable::Moveable()
: velocity(0,0)				//initialize
{

}

void Moveable::setSpeed(float Speed)
{
	fSpeed = Speed;
}

void Moveable::resetVelocity()
{
	velocity = sf::Vector2f(0.f,0.f);
}

float Moveable::getSpeed() 
{
	return fSpeed;
}

sf::Vector2f Moveable::getVelocity()
{
	return velocity;
}

MyEnum::Direction Moveable::getDirection()
{
	return direction;
}

bool Moveable::isMoving()
{
	if (velocity == sf::Vector2f(0.f,0.f)) {
		return false;
	} else {
		return true;
	}
}
