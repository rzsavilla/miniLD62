#include <PlayScreen.h>

PlayScreen::PlayScreen()
{

}
 
void PlayScreen::initialize(sf::Vector2u windowSize)
{
	font.loadFromFile("assets/fonts/arial.ttg");

	Text_PlayScreen.setFont(font);
	Text_PlayScreen.setString("Play Screen");
	Text_PlayScreen.setCharacterSize(50);
	Text_PlayScreen.setColor(sf::Color::Red);
}

void PlayScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Text_PlayScreen,states);
}