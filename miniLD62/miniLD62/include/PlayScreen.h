#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <MyEnum.h>

#include <Player.h>

class PlayScreen: public sf::Drawable
{
public:
	PlayScreen();
	
	void initialize(sf::Vector2u windowSize);			//Takes Screen Size for HUD positioning
	MyEnum::State update(InputHandler& input);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	Player player;

	//Player
	//Map/Grid
	//Background
	//Projectiles
	//Collision
};

#endif