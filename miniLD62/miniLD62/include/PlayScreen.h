#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class PlayScreen: public sf::Drawable
{
public:
	PlayScreen();
	void initialize(sf::Vector2u windowSize);			//Takes Screen Size for HUD positioning

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Font font;						//Testing
	sf::Text Text_PlayScreen;
	//Player
	//Map/Grid
	//Background
	//Projectiles
	//Collision
};

#endif