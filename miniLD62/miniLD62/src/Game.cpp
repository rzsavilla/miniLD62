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

	Start_Screen.initialize(sf::Vector2u(uiWidth,uiHeight));
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
			input.mousePos = sf::Mouse::getPosition(window);
		}
	}
}

void Game::update(sf::Time dt)
{
	switch (gameState)
	{
	case MyEnum::Start:
		if (input.bSpace) {
			gameState = MyEnum::Play;
		}
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