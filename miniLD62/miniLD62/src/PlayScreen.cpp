#include <PlayScreen.h>
#include <iostream>
PlayScreen::PlayScreen()
{

}
 
void PlayScreen::initialize(sf::Vector2u windowSize)
{
	player.initialize(windowSize);
}

MyEnum::State PlayScreen::update(InputHandler& input)
{
	MyEnum::State currentState = MyEnum::State::Play;

	player.update(input);

	return currentState;
}

void PlayScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(player,states);
}
