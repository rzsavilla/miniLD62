#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <InputHandler.h>
#include <MyEnum.h>
#include <Resources_Text.h>
#include <FPSCounter.h>

#include <StartScreen.h>
#include <PlayScreen.h>
#include <ExitScreen.h>
#include <GameOverScreen.h>

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
	Resources_Text textResources;
	FPSCounter fps;
	StartScreen Start_Screen;
	PlayScreen Play_Screen;
	GameOverScreen Over_Screen;
private:
	void handleEvents();
	void update(sf::Time dt);
	void render();

	//Update Game Screens;
	void updateStart(sf::Time dt);
	void updatePlay(sf::Time dt);
	void updatePause(sf::Time dt);

};

#endif
