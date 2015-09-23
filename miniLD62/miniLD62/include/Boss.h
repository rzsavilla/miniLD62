#ifndef BOSS_H
#define BOSS_H

#include <AnimatedSprite.h>
#include <Animation.h>
#include <Health.h>

class Boss: public AnimatedSprite, public Health
{
public:
	Boss();

	void initialize();
private:

};

#endif