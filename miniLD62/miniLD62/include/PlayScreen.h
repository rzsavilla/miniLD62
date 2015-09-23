#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <MyEnum.h>
#include <SFML/Graphics/Sprite.hpp>

#include <Player.h>

class PlayScreen: public sf::Drawable
{
public:
	PlayScreen();
	
	void initialize(sf::Vector2u windowSize);			//Takes Screen Size for HUD positioning
	MyEnum::State update(InputHandler& input, sf::Time dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	Player player;
	sf::Sprite grid;
	sf::Texture gridTexture;

	//Player
	//Map/Grid
	//Background
	//Projectiles
	//Collision
};

#endif