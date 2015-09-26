#ifndef PROJECTILEHANDLER_H
#define PROJECTILEHANDLER_H

#include <vector>
#include <Projectile.h>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <Destroyed.h>

class ProjectileHandler: public sf::Drawable
{
public:
	ProjectileHandler();

	void setProjectile(Projectile& proj);

	void updateProjectiles(sf::Time dt);
	std::vector <Projectile> projectiles;
	int projCount();
	void Shoot(sf::Vector2f position,sf::Vector2f target);

	bool collision(sf::FloatRect rect);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
protected:
	
private:
	bool bHasProjectile;
	Projectile projectile;
};

#endif
