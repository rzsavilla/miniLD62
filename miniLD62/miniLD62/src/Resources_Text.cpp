#include <Resources_Text.h>
#include <iostream>

Resources_Text::Resources_Text()
{
	//initialize();
}

void Resources_Text::initialize()
{
	if (!arial.loadFromFile("assets/fonts/arial.ttf")) {
		std::cout << "Arial Font could not be loaded\n";
	}
}

void Resources_Text::setText(sf::Text& text, sf::Font& font, sf::Color color, int iSize, sf::Vector2f pos, std::string string)
{
	text.setFont(font);
	text.setColor(color);
	text.setCharacterSize(iSize);
	text.setPosition(pos);
	text.setString(string);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
}

