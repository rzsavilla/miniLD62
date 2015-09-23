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
	void update(InputHandler& input, sf::Time dt);

	void setMoveDelay(float Delay);
private:
	float fMoveDelay;
	sf::Clock moveTimer;						//for move Delay
	bool bJustMoved;
	void playerInputs(InputHandler& input, sf::Time dt);
	float fMoveDist;								//move distance
	//Animation
	Animation moveAnimation;
	Animation movingUp;
	Animation movingDown;
	Animation movingLeft;
	Animation movingRight;

	sf::Vector2f targetpos;
	void calcNewPos();				//Target Position
	void getDistance();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void updateMovement(sf::Time dt);
};

#endif