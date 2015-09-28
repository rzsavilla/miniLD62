#include <PickupHandler.h>

PickupHandler::PickupHandler()
{
	iMax = 1;
}

void PickupHandler::spawn(Pickup& pickup,sf::Vector2f position)
{
	if (pickups.size() < iMax) {
		//Can Spawn
		pickups.push_back(pickup);
		pickups.back().setPosition(position);
	}
}

void PickupHandler::update()
{
	for (int i = 0; i < pickups.size(); i++) {
		pickups[i].update();		//Update pickup
		pickups[i].animate();
	}

	for (int i = 0; i < pickups.size(); i++) {
		if (pickups[i].isDestroyed()) {
			std::cout << "Destroy\n\n\n";
			pickups.erase(pickups.begin() + i);
		}
	}
}

void PickupHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < pickups.size(); i++) {
		target.draw(pickups[i], states);
	}
}
