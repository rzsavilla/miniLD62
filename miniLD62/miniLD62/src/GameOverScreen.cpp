#include <GameOverScreen.h>
#include <iostream>

GameOverScreen::GameOverScreen()
{

}

void GameOverScreen::initialize(sf::Vector2u screenSize)
{
	//Load Fonts
	if (!font.loadFromFile("assets/fonts/arial.ttf")) {
		std::cout << "Font could not be loaded\n";
	}
	setText(Text_GameOver,font, sf::Color::Red, 100, sf::Vector2f(screenSize.x / 2, screenSize.y / 5), "MiniLD62");
	setText(Text_Score,font, sf::Color::Red, 30, sf::Vector2f(screenSize.x / 2, screenSize.y / 2), "Play");
}

void GameOverScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Text_GameOver, states);
	target.draw(Text_Score, states);
}

void GameOverScreen::setText(sf::Text& text, sf::Font& font, sf::Color color, int iSize, sf::Vector2f pos, std::string string)
{
	text.setFont(font);
	text.setColor(color);
	text.setCharacterSize(iSize);
	text.setPosition(pos);
	text.setString(string);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
}

MyEnum::State GameOverScreen::update(InputHandler& input)
{
	MyEnum::State currentState = MyEnum::State::Start;

	if (input.mouseCollision(Text_GameOver.getGlobalBounds())) {  //Mouse is on text
		if (input.bLeftClick) {
			currentState = MyEnum::State::Play;
			input.bLeftClick = false;
		}
	} else if (input.mouseCollision(Text_Score.getGlobalBounds())) {
		if (input.bLeftClick) {
			currentState = MyEnum::State::Exit;
			input.bLeftClick = false;
		}
	}
	return currentState;		//Returns Game State current/new
}