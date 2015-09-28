#ifndef BOSS_H
#define BOSS_H

#include <AnimatedSprite.h>
#include <AnimatedRect.h>
#include <Animation.h>
#include <Health.h>
#include <Inputhandler.h>

class Boss: public AnimatedSprite, public Health
{
public:
	Boss();
	void initialize();

	void update(sf::Vector2f playerPos);
private:
	Animation animation;
};

#endif