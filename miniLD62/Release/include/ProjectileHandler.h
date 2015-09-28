#ifndef PROJECTILEHANDLER_H
#define PROJECTILEHANDLER_H

#include <vector>
#include <Projectile.h>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <Destroyed.h>
#include <MyEnum.h>

class ProjectileHandler: public sf::Drawable
{
public:
	ProjectileHandler();

	void setProjectile(Projectile& proj);

	void updateProjectiles(sf::Time dt);
	std::vector <Projectile> projectiles;
	int projCount();
	void Shoot(sf::Vector2f position,sf::Vector2f target);
	void Shoot(sf::Vector2f position, MyEnum::Direction direction, float fSpeed);

	bool collision(sf::FloatRect rect);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	Projectile projectile;
protected:
	
private:
	bool bHasProjectile;
	
};

#endif
