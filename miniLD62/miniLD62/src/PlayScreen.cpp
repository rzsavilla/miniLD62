#include <PlayScreen.h>
#include <iostream>
PlayScreen::PlayScreen()
{

}
 
void PlayScreen::initialize(sf::Vector2u windowSize)
{
	//Player
	player.initialize(windowSize);

	//Grid
	gridTexture.loadFromFile("assets/textures/placeholder_grid.png");
	grid.setTexture(gridTexture);
}

MyEnum::State PlayScreen::update(InputHandler& input, sf::Time dt)
{
	MyEnum::State currentState = MyEnum::State::Play;

	player.update(input, dt);

	return currentState;
}

void PlayScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(grid,states);
	target.draw(player,states);
}
