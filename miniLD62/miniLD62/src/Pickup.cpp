#include <Pickup.h>

Pickup::Pickup()
{
	bActivated = false;
	fDuration = 5.f;
}

void Pickup::setDuration(float Duration)
{
	fDuration = Duration;
}

void Pickup::activate()
{

}

bool Pickup::hasActivated()
{
	return bActivated;
}

void Pickup::update()
{
	animate();
}
