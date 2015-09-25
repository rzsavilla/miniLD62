#ifndef BOSS_H
#define BOSS_H

#include <AnimatedSprite.h>
#include <Animation.h>
#include <Health.h>

#include <Inputhandler.h>

class Boss: public AnimatedSprite, public Health
{
public:
	Boss();
	void initialize();

	void update();
private:
	Animation animation;
};

#endif