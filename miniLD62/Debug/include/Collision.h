#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics/Rect.hpp>

class Collision
{
public:
	Collision();

	void setBounds();
private:
	sf::FloatRect topBB;
	sf::FloatRect bottomBB;
	sf::FloatRect leftBB;
	sf::FloatRect rightBB;
};

#endif