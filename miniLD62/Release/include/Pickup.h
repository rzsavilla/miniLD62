#ifndef PICKUP_H
#define PICKUP_H

#include <AnimatedSprite.h>
#include <Destroyed.h>

class Pickup: public AnimatedSprite, public Destroyed
{
public:
	Pickup();

	void setDuration(float Duration);

	void activate();
	bool hasActivated();
	void update();
private:
	sf::Clock timer;
	float fDuration;
	bool bActivated;
};
#endif