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

class PlayScreen: public sf::Drawable
{
public:
	PlayScreen();
	
	void initialize(sf::Vector2u windowSize, Resources_Text& resources);			//Takes Screen Size for HUD positioning
	MyEnum::State update(InputHandler& input, sf::Time dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:

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

	//Player
	//Map/Grid
	//Background
	//Projectiles
	//Collision
};

#endif