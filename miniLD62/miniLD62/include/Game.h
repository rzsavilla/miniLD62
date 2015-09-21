#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <InputHandler.h>
#include <MyEnum.h>

class Game
{
public:
	Game();
	void initialize();
	void run();
private:
	unsigned int uiWidth, uiHeight;								//Window Size
	sf::RenderWindow window;
	InputHandler input;
	sf::Clock timer;
	MyEnum::State gameState;
private:
	void handleEvents();
	void update(sf::Time dt);
	void render();
};

#endif
