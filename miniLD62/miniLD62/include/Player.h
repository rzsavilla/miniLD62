#ifndef PLAYER_H
#define PLAYER_H

#include <AnimatedSprite.h>
#include <SFML/Graphics/Texture.hpp>
#include <Health.h>
#include <inputHandler.h>
#include <Moveable.h>

class Player:public AnimatedSprite, public Health, public Moveable
{
public:
	Player();
	void initialize(sf::Vector2u screenSize);
	void update(InputHandler& input);

	void setMoveDelay(float Delay);
private:
	float fMoveDelay;
	sf::Clock moveTimer;						//for move Delay
	bool bJustMoved;
	void playerInputs(InputHandler& input);
	//Animation
	Animation moveAnimation;
	Animation movingUp;
	Animation movingDown;
	Animation movingLeft;
	Animation movingRight;
};

#endif