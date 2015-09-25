#ifndef HEALTH_H
#define HEALTH_H

class Health
{
public:
	Health();

	void setHealth(int Health);
	void damage(int Damage);			//take away from health

	int& getHealth();
	bool isDead();						//Checks play Health
private:
	int iHealth;
};

#endif
