#ifndef PICKUPHANDLER_H
#define PICKUPHANDLER_H

#include <Pickup.h>
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class PickupHandler: public sf::Drawable
{
public:
	PickupHandler();

	void setMax(int Max);				//Maximum pickups that can be spawned

	void spawn(Pickup& pickup,sf::Vector2f position);
	void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::vector <Pickup> pickups;
private:
	int iMax;
};

#endif