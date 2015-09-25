#include <Destroyed.h>

Destroyed::Destroyed()
{
	bDestroyed = false;
}

void Destroyed::destroy()
{
	bDestroyed = true;
}

bool Destroyed::isDestroyed()
{
	return bDestroyed;
}



