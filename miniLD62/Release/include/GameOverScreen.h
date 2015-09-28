#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <SFML/Graphics.hpp>

#include <InputHandler.h>
#include <MyEnum.h>

class GameOverScreen: public sf::Drawable
{
public:
	GameOverScreen();
	void initialize(sf::Vector2u screenSize);
	MyEnum::State update(InputHandler& input);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Text Text_GameOver;
	sf::Text Text_Score;
	sf::Font font;
	void setText(sf::Text& text, sf::Font& font, sf::Color color, int iSize, sf::Vector2f pos, std::string string);
	void textSelect();
};
#endif
