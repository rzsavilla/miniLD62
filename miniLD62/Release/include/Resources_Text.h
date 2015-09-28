#ifndef RESOURCES_TEXT_H
#define RESOURCES_TEXT_H

//Will store fonts, strings, functions etc. to create Text Graphics

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Resources_Text
{
public:
	Resources_Text();

	void initialize();
	sf::Font arial;
	sf::Font acme;

	void setText(sf::Text& text, sf::Font& font, sf::Color color, int iSize, sf::Vector2f pos, std::string string);
private:

protected:
	
};

#endif