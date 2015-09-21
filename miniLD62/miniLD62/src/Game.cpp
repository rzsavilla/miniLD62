#include <Game.h>

Game::Game()
: window(sf::VideoMode(640,480),"Game",sf::Style::Titlebar|sf::Style::Close)
{

}

void Game::initialize()
{
	uiWidth = 640;
	uiHeight = 480;
	window.setSize(sf::Vector2u(uiWidth,uiHeight));
	gameState = MyEnum::State::Start;					//Begins at the start screen
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
	}
}

void Game::update(sf::Time dt)
{
	switch (gameState)
	{
	case MyEnum::Start:
		break;
	case MyEnum::Play:
		break;
	case MyEnum::Pause:
		break;
	case MyEnum::GameOver:
		break;
	case MyEnum::Exit:
		break;
	default:
		break;
	}
	//StartScreen

	//PlayScreen

	//PauseScreen
}

void Game::render()
{
	window.clear(sf::Color::White);

	switch (gameState)
	{
	case MyEnum::Start:
		break;
	case MyEnum::Play:
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