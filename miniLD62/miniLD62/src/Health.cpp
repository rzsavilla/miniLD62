#include <Health.h>

Health::Health()
{

}

void Health::setHealth(int Health) 
{
	iHealth = Health;
}

void Health::damage(int Damage) 
{
	iHealth -= Damage;
}

int& Health::getHealth()
{
	return iHealth;
}

bool Health::isDead()
{
	bool bDead = false;
	if (iHealth <= 0) {
		bDead = true;
	}
	return bDead;
}




