#include <PlayScreen.h>
#include <iostream>
PlayScreen::PlayScreen()
{

}
 
void PlayScreen::initialize(sf::Vector2u windowSize, Resources_Text& resources)
{
	//Player
	player.initialize(windowSize);
	//Boss
	boss.initialize();
	boss.setHealth(10000);
	//Grid
	gridTexture.loadFromFile("assets/textures/Grid_Background.png");
	grid.setTexture(gridTexture);

	//HUD - Head Up Display
	hud.initialize(windowSize, resources);
	hud.setBossHealth(boss.getHealth());
}

MyEnum::State PlayScreen::update(InputHandler& input, sf::Time dt)
{
	MyEnum::State currentState = MyEnum::State::Play;

	player.update(input, dt);
	boss.update();
	hud.setHealth(player.getHealth());
	hud.setLives(player.getLives());
	if (input.bSpace) {
		boss.setHealth(boss.getHealth() -= 10);
		hud.updateBossHealth(boss.getHealth());
		input.bSpace = false;
	}
	std::cout << boss.getHealth() << std::endl;

	player.setHealth(player.getHealth());

	//Victory Check
	if (boss.getHealth() <= 0) {
		currentState = MyEnum::State::GameOver;
	}
	return currentState;
}

void PlayScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(grid,states);
	target.draw(player,states);
	target.draw(boss,states);
	target.draw(hud, states);
}
