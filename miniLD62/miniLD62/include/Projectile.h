#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <Moveable.h>
#include <Animation.h>
#include <AnimatedSprite.h>
#include <Destroyed.h>

class Projectile: public Moveable, public Destroyed, public AnimatedSprite
{
public:
	Projectile();

	void set(float Speed, Animation& anim, sf::Vector2f pos);
	void setTargetPos(sf::Vector2f position);					//Move towards this point
	void setTargetPos(float x, float y);
	void collided();											//Collision has occured set to true

	bool hasCollided();
	bool hasReachedTarget();
	void moveProjectile(sf::Time dt);
private:
	bool bCollided;
	bool reachedTarget;
	sf::Vector2f targetPos;
	Animation animation;
	float fDistance;
};

#endif