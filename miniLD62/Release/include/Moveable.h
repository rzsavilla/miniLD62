#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <MyEnum.h>
#include <SFML/Graphics.hpp>

class Moveable
{
public:
	Moveable();

	void setSpeed(float Speed);
	void setVelocity(sf::Vector2f vel);
	void resetVelocity();
	void allowMove(bool EnableMovement);

	float getSpeed();
	sf::Vector2f getVelocity();
	MyEnum::Direction getDirection();			//get direction facing
	bool isMoving();							//Checks velocity
private:
	float fSpeed;
protected:
	MyEnum::Direction direction;
	sf::Vector2f velocity;
};
#endif
