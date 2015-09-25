#include <Projectile.h>
#include <cmath>
#include <iostream>

Projectile::Projectile()
{
	reachedTarget = false;
}

void Projectile::set(float Speed, Animation& anim, sf::Vector2f pos) 
{
	setSpeed(Speed);
	/*
	setAnimation(anim);
	playAnimation();
	*/
	//setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
}

void Projectile::setTargetPos(sf::Vector2f position) 
{
	targetPos = position;
}

void Projectile::setTargetPos(float x, float y)
{
	targetPos.x = x;
	targetPos.y = y;
}

bool Projectile::hasReachedTarget()
{
	return reachedTarget;
}

void Projectile::moveProjectile(sf::Time dt)
{
	if (!reachedTarget) {
		sf::Vector2f pos = getPosition();
		fDistance = sqrt(pow(targetPos.x - pos.x,2) + pow(targetPos.y - pos.y,2));

		//Calculate new velocity
		velocity.x = getSpeed() * (targetPos.x - pos.x) / fDistance;
		velocity.y = getSpeed() * (targetPos.y - pos.y) / fDistance; 

		if (fDistance > -1 && fDistance < 1)
		{
			reachedTarget = true;
			resetVelocity();
		}
		move(getVelocity() * dt.asSeconds());
	}
}
