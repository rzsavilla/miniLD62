#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <MyEnum.h>
#include <Resources_Text.h>

#include <Hud.h>
#include <Player.h>
#include <Boss.h>

#include <Projectile.h>
#include <ProjectileHandler.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <Pickup.h>
#include <PickupHandler.h>

#include <cstdlib>		//Rand

class PlayScreen: public sf::Drawable
{
public:
	PlayScreen();
	
	void initialize(sf::Vector2u windowSize, Resources_Text& resources);			//Takes Screen Size for HUD positioning
	MyEnum::State update(InputHandler& input, sf::Time dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Clock damageTimer;
	sf::Vector2u window;
	//Hud
	Hud hud;

	//Player
	Player player;
	int iHealth_Player;
	
	//Map
	sf::Sprite grid;
	sf::Texture gridTexture;

	//Boss
	Boss boss;
	int BossHealth;
	sf::FloatRect bossCollRect;

	//Projectiles
	Projectile fireball;
	ProjectileHandler playerProj;
	ProjectileHandler bossProj;

	void updatePlayerProj(InputHandler& input, sf::Time dt);
	void updateBossProj(InputHandler& input, sf::Time dt);

	//Animation
	Animation rock_Animation;
	Animation bullet_Explode;

	//Player
	//Map/Grid
	//Background
	//Projectiles
	//Collision

	sf::RectangleShape shape;
	sf::FloatRect safeZone;				//Player will take damage over time if not standing here

	//Wall
	sf::FloatRect topBB;
	sf::FloatRect botBB;
	sf::FloatRect lefBB;
	sf::FloatRect rigBB;

	//Pickups
	sf::Clock pickupTimer;
	Animation Animation_Mana_Pickup;
	Pickup Pickup_Mana;
	PickupHandler pickups;
	void updatePickups(sf::Vector2u windowSize);


	sf::Clock bossTimer;
	sf::Clock attackTimer;
	int BossSkill;

	bool bNormal;
	bool bAssault;
};

#endif