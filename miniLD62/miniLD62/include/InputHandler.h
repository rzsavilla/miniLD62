#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class InputHandler
{
public:
	InputHandler();

	void initialize();

	void handleKeyPress(sf::Keyboard::Key key, bool isPressed);
	void handleMousePress(sf::Mouse::Button button, bool isPressed);
	void handleMouseMove(sf::Vector2i pos);

	bool mouseCollision(sf::FloatRect rect);
public:
	bool bUp, bDown, bLeft, bRight;
	bool bSpace;
	bool bLeftClick, bRightClick;
	bool bPause;
	sf::Vector2i mousePos;
	sf::FloatRect mouseRect;
};
#endif