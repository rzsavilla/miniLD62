#include <ProjectileHandler.h>
#include <iostream>

ProjectileHandler::ProjectileHandler()
{
	bHasProjectile = false;
}

void ProjectileHandler::setProjectile(Projectile& proj)
{
	projectile = proj;
	bHasProjectile = true;
}

void ProjectileHandler::Shoot(sf::Vector2f position,sf::Vector2f target)
{
	if (bHasProjectile) {
		projectile.setPosition(position);
		projectile.setTargetPos(target);
		projectiles.push_back(projectile);
	} else {
		std::cout << "No Projectile has been set\n";
	}
}

void ProjectileHandler::updateProjectiles(sf::Time dt)
{
	if (projectiles.size() > 0) {
		for (int i = 0; i < projectiles.size(); i++) {
			projectiles[i].moveProjectile(dt);
		}
	}
}

int ProjectileHandler::projCount()
{
	return projectiles.size();
}
