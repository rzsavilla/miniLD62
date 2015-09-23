#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <Moveable.h>
#include <Animation.h>
#include <AnimatedSprite.h>
#include <SFML/Graphics/RectangleShape.hpp>

class Projectile: public Moveable, public sf::RectangleShape
{
public:
	Projectile();

	void set(float Speed, Animation& anim, sf::Vector2f pos);
	void setTargetPos(sf::Vector2f position);					//Move towards this point
	void setTargetPos(float x, float y);
	
	bool hasReachedTarget();
	void moveProjectile(sf::Time dt);
private:
	bool reachedTarget;
	sf::Vector2f targetPos;
	Animation animation;
	float fDistance;
};

#endif