#include <StartScreen.h>
#include <iostream>

StartScreen::StartScreen()
{

}

void StartScreen::initialize(sf::Vector2u screenSize, Resources_Text& resources)
{
	resources.setText(Text_Title,resources.arial, sf::Color::Red, 100, sf::Vector2f(screenSize.x / 2, screenSize.y / 5), "MiniLD62");
	resources.setText(Text_Play,resources.arial, sf::Color::Red, 30, sf::Vector2f(screenSize.x / 2, screenSize.y / 2), "Play");
	resources.setText(Text_Exit,resources.arial, sf::Color::Red, 30, sf::Vector2f(screenSize.x / 2, screenSize.y / 1.5), "Exit");
}

void StartScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Text_Title, states);
	target.draw(Text_Play, states);
	target.draw(Text_Exit,states);
}

MyEnum::State StartScreen::update(InputHandler& input)
{
	MyEnum::State currentState = MyEnum::State::Start;

	if (input.mouseCollision(Text_Play.getGlobalBounds())) {  //Mouse is on text
		if (input.bLeftClick) {
			currentState = MyEnum::State::Play;
			input.bLeftClick = false;
		}
	} else if (input.mouseCollision(Text_Exit.getGlobalBounds())) {
		if (input.bLeftClick) {
			currentState = MyEnum::State::Exit;
			input.bLeftClick = false;
		}
	}
	return currentState;		//Returns Game State current/new
}
