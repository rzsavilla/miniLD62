#ifndef PLAYER_H
#define PLAYER_H

#include <AnimatedSprite.h>
#include <SFML/Graphics/Texture.hpp>
#include <Health.h>
#include <inputHandler.h>
#include <Moveable.h>
#include <Destroyed.h>
#include <ProjectileHandler.h>
#include <Projectile.h>

class Player:public AnimatedSprite, public Health, public Moveable, public Destroyed
{
public:
	Player();
	void initialize(sf::Vector2u screenSize);
	void update(InputHandler& input, sf::Time dt);

	void setLives(int Lives);
	void setMoveDelay(float Delay);
	void setFireRate(float Rate);
	void setMana(int Mana);
	void addMana(int i);
	void useMana(int i);
	int getMana();

	float getRateOfFire();

	ProjectileHandler spells;

	bool bCanShoot;

	void resetPosition();

	void moveUp();					//Changes player velocity
	void moveDown();
	void moveLeft();
	void moveRight();
private:
	int iSpell;				//Spell Selected
	int iMana;				//Used to cast spells
	int iMaxMana;			//Max Mana

	void playerInputs(InputHandler& input, sf::Time dt);
	sf::Vector2f startPos;		//Player Starting Position
	
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
	
	void updateMovement(sf::Time dt);

	float fFireRate;
	sf::Clock weaponTimer;

	sf::Clock manaRegen;
};

#endif