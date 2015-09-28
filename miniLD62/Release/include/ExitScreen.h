#ifndef EXITSCREEN_H
#define EXITSCREEN_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Clock.hpp>

#include <MyEnum.h>
#include <InputHandler.h>

class ExitScreen: public sf::Drawable
{
public:
	ExitScreen();

	void initialize(sf::Vector2u windowSize);

	MyEnum::State update(InputHandler& input);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Clock timer;
};

#endif
