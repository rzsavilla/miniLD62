#ifndef PLAYER_H
#define PLAYER_H

#include <AnimatedSprite.h>
#include <SFML/Graphics/Texture.hpp>
#include <Health.h>
#include <inputHandler.h>
#include <Moveable.h>
#include <Destroyed.h>

class Player:public AnimatedSprite, public Health, public Moveable, public Destroyed
{
public:
	Player();
	void initialize(sf::Vector2u screenSize);
	void update(InputHandler& input, sf::Time dt);

	void setLives(int Lives);
	void setMoveDelay(float Delay);

	int getLives();
private:
	int iLives;
	void playerInputs(InputHandler& input, sf::Time dt);
	
	//Animation
	sf::Texture spriteSheet;
	Animation idleAnimation;
	Animation movingUp;
	Animation movingDown;
	Animation movingLeft;
	Animation movingRight;
	
	//Movement
	float fMoveDelay;				//Wait time until player can move again
	sf::Clock moveTimer;			//for move Delay
	bool bJustMoved;				//Cannot move if true
	float fMoveDist;				//move distance

	sf::Vector2f targetpos;
	void calcNewPos();				//Target Position
	void getDistance();
	void moveUp();					//Changes player velocity
	void moveDown();
	void moveLeft();
	void moveRight();
	void updateMovement(sf::Time dt);
};

#endif