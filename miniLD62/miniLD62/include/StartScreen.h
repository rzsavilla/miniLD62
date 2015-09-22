#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <SFML/Graphics.hpp>

#include <InputHandler.h>
#include <MyEnum.h>

class StartScreen: public sf::Drawable
{
public:
	StartScreen();
	void initialize(sf::Vector2u screenSize);
	MyEnum::State update(InputHandler& input);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Text Text_Title;
	sf::Text Text_Play;
	sf::Text Text_Exit;
	sf::Font font;
	void setText(sf::Text& text, sf::Font& font, sf::Color color, int iSize, sf::Vector2f pos, std::string string);
	void textSelect();
};
#endif
