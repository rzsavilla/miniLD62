#include <Game.h>
#include <iostream>
Game::Game()
: window(sf::VideoMode(640,480),"Game",sf::Style::Titlebar|sf::Style::Close)
{

}

void Game::initialize()
{
	textResources.initialize();
	uiWidth = 640;
	uiHeight = 480;
	window.setSize(sf::Vector2u(uiWidth,uiHeight));
	window.setKeyRepeatEnabled(true);
	window.setFramerateLimit(60);
	gameState = MyEnum::State::Start;					//Begins at the start screen

	Start_Screen.initialize(sf::Vector2u(uiWidth,uiHeight), textResources);
	Play_Screen.initialize(sf::Vector2u(uiWidth,uiHeight), textResources);
}

void Game::run()
{
	while (window.isOpen()) {
		sf::Time dt = timer.restart();
		handleEvents();
		update(dt);
		render();
	}
}

void Game::handleEvents()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		//Close Window
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		//Key Press
		if (event.type == sf::Event::KeyPressed) {
			input.handleKeyPress(event.key.code, true);
		} else if (event.type == sf::Event::KeyReleased) {
			input.handleKeyPress(event.key.code, false);
		}

		//Mouse
		if(event.type == sf::Event::MouseMoved) {
			//Update mouse position
			input.handleMouseMove(sf::Mouse::getPosition(window));
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			input.handleMousePress(event.mouseButton.button, true);
		} else if (event.type == sf::Event::MouseButtonReleased) {
			input.handleMousePress(event.mouseButton.button,false);
		}
	}
}

void Game::update(sf::Time dt)
{
	switch (gameState)
	{
	case MyEnum::Start:
		gameState = Start_Screen.update(input);
		break;
	case MyEnum::Play:
		gameState = Play_Screen.update(input, dt);
		//std::cout << "Play Screen\n";
		break;
	case MyEnum::Pause:
		//std::cout << "Pause Screen\n";
		break;
	case MyEnum::GameOver:
		//std::cout << "Game Over Screen\n";
		break;
	case MyEnum::Exit:
		//std::cout << "Exit Screen\n";
		break;
	default:
		break;
	}
}

void Game::render()
{
	window.clear(sf::Color::Black);
	switch (gameState)
	{
	case MyEnum::Start:
		window.draw(Start_Screen);
		break;
	case MyEnum::Play:
		window.draw(Play_Screen);
		break;
	case MyEnum::Pause:
		break;
	case MyEnum::GameOver:
		break;
	default:
		break;
	}
	window.display();
}