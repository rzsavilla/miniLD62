#ifndef PROJECTILEHANDLER_H
#define PROJECTILEHANDLER_H

#include <vector>
#include <Projectile.h>

class ProjectileHandler
{
public:
	ProjectileHandler();

	void setProjectile(Projectile& proj);

	void updateProjectiles(sf::Time dt);
	std::vector <Projectile> projectiles;
	int projCount();
protected:
	void Shoot(sf::Vector2f position,sf::Vector2f target);
private:
	bool bHasProjectile;
	Projectile projectile;
};

#endif
