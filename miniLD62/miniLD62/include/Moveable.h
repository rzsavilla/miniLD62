#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <MyEnum.h>
#include <SFML/Graphics.hpp>

class Moveable
{
public:
	Moveable();

	void setSpeed(float Speed);
	void resetVelocity();

	float getSpeed();
	sf::Vector2f getVelocity();

	MyEnum::Direction getDirection();			//get direction facing
private:
	float fSpeed;
	MyEnum::Direction direction;
	sf::Vector2f velocity;
protected:
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};
#endif
