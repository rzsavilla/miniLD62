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

void ProjectileHandler::Shoot(sf::Vector2f position, MyEnum::Direction direction, float fSpeed)
{
	sf::Vector2f velocity(0.f,0.f);
	switch (direction)
	{
	case MyEnum::Up:
		velocity.y -=  fSpeed;
		break;
	case MyEnum::Down:
		velocity.y +=  fSpeed;
		break;
	case MyEnum::Left:
		velocity.x -=  fSpeed;
		break;
	case MyEnum::Right:
		velocity.x +=  fSpeed;
		break;
	default:
		break;
	}
	if (bHasProjectile) {
		projectiles.push_back(projectile);
		projectiles.back().setPosition(position);
		projectiles.back().setVelocity(velocity);
	} else {
		std::cout << "No Projectile has been set\n";
	}
}


void ProjectileHandler::updateProjectiles(sf::Time dt)
{
	for (int i = 0; i < projectiles.size(); i++) {
		if (projectiles[i].isDestroyed()) {
			//Animation if finished playing
			projectiles.erase(projectiles.begin());
		}
	}

	for (int i = 0; i < projectiles.size(); i++) {
		//Check if destroyed
		if (projectiles[i].isDestroyed()) {
			//Animation if finished playing
			projectiles.erase(projectiles.begin() + i);
		}
		//Update Movement
		projectiles[i].moveProjectile(dt);
	}
}

int ProjectileHandler::projCount()
{
	return projectiles.size();
}

bool ProjectileHandler::collision(sf::FloatRect rect)
{
	bool bCollision = false;

	for (int i = 0; i <  projectiles.size(); i++) {
		if (projectiles[i].getGlobalBounds().intersects(rect)) {
			bCollision = true;
			projectiles[i].destroy();		//Projectile to be destroyed
		}
	}
	return bCollision;
}


void ProjectileHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(int i = 0; i < projectiles.size(); i++) {
		target.draw(projectiles[i], states);
	}
}

