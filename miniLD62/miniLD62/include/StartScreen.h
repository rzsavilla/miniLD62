#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <SFML/Graphics.hpp>

#include <InputHandler.h>
#include <MyEnum.h>
#include <Resources_Text.h>

class StartScreen: public sf::Drawable
{
public:
	StartScreen();
	void initialize(sf::Vector2u screenSize, Resources_Text& resources);
	MyEnum::State update(InputHandler& input);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Text Text_Title;
	sf::Text Text_Play;
	sf::Text Text_Exit;
	sf::Font font;
	void textSelect();
};
#endif
