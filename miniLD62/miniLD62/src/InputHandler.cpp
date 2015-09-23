#include <Inputhandler.h>
#include <iostream>
InputHandler::InputHandler()
{
	initialize();
}

void InputHandler::initialize()
{
	bUp = false, bDown = false, bLeft = false, bRight = false;
	bSpace = false;
	bLeftClick = false, bRightClick = false;
	mousePos.x = 0.f;
	mousePos.y = 0.f;
	bPause = false;
}

void InputHandler::handleKeyPress(sf::Keyboard::Key key, bool isPressed) 
{
	switch (key)
	{
	case sf::Keyboard::Unknown:
		break;
	case sf::Keyboard::A:
		bLeft = isPressed;
		break;
	case sf::Keyboard::D:
		bRight = isPressed;
		break;
	case sf::Keyboard::P:
		bPause = isPressed;
		break;
	case sf::Keyboard::S:
		bDown = isPressed;
		break;
	case sf::Keyboard::W:
		bUp = isPressed;
		break;
	case sf::Keyboard::Space:
		bSpace = isPressed;
		break;
	case sf::Keyboard::Left:
		bLeft = isPressed;
		break;
	case sf::Keyboard::Right:
		bRight = isPressed;
		break;
	case sf::Keyboard::Up:
		bUp = isPressed;
		break;
	case sf::Keyboard::Down:
		bDown = isPressed;
		break;
	default:
		break;
	}
}

void InputHandler::handleMousePress(sf::Mouse::Button button, bool isPressed)
{
	switch (button)
	{
	case sf::Mouse::Left:
		bLeftClick = isPressed;
		break;
	case sf::Mouse::Right:
		bRightClick = isPressed;
		break;
	case sf::Mouse::Middle:
		break;
	case sf::Mouse::XButton1:
		break;
	case sf::Mouse::XButton2:
		break;
	case sf::Mouse::ButtonCount:
		break;
	default:
		break;
	}
}

void InputHandler::handleMouseMove(sf::Vector2i pos)
{
	//Update Position and Rect;
	mousePos = pos;
	mouseRect = sf::FloatRect(pos.x,pos.y,1,1);
}

bool InputHandler::mouseCollision(sf::FloatRect rect)
{
	bool bCollision = false;
	if (mouseRect.intersects(rect)) {
		bCollision = true;
	}
	return bCollision;
}
