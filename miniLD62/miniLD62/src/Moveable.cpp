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

void Moveable::moveUp()
{
	velocity.y -= fSpeed;
	direction = MyEnum::Direction::Up;
}

void Moveable::moveDown()
{
	velocity.y += fSpeed;
	direction = MyEnum::Direction::Down;
}

void Moveable::moveLeft()
{
	velocity.x -= fSpeed;
	direction = MyEnum::Direction::Left;
}

void Moveable::moveRight()
{
	velocity.x += fSpeed;
	direction = MyEnum::Direction::Right;
}

