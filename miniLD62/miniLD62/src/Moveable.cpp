#include <Moveable.h>
#include <iostream>

Moveable::Moveable()
: velocity(0,0)				//initialize
{

}

void Moveable::setSpeed(float Speed)
{
	fSpeed = Speed;
}

void Moveable::setVelocity(sf::Vector2f vel)
{
	velocity.x = vel.x;
	velocity.y = vel.y;
}

void Moveable::resetVelocity()
{
	velocity = sf::Vector2f(0.f,0.f);
}

void Moveable::allowMove(bool EnableMovement)
{

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
	bool bMoving = true;
	if (velocity == sf::Vector2f(0.f,0.f)) {
		bMoving = false;
	}
	return bMoving;
}
