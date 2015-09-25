#include <Hud.h>
#include <iostream>

Hud::Hud()
{

}
 
void Hud::initialize(sf::Vector2u windowSize, Resources_Text& resources)
{
	float fOffsetX = 50;		//For Positioning
	float fOffsetY = 40;
	sf::Vector2f bottomLeft(fOffsetX,windowSize.y - fOffsetY);
	sf::Vector2f bottomRight(windowSize.x - fOffsetX * 2,windowSize.y - fOffsetY);
	sf::Vector2f topCenter(windowSize.x / 2, fOffsetY);

	resources.setText(Text_Health,resources.arial,sf::Color::White, 20.f,bottomLeft,"Health: ");
	resources.setText(Text_Lives,resources.arial,sf::Color::White, 20.f,bottomRight,"Health: ");
	resources.setText(Text_BossHealth,resources.arial,sf::Color::White, 20.f,topCenter,"1000");
	Text_BossHealth.setOrigin(Text_BossHealth.getGlobalBounds().width / 2 , Text_BossHealth.getCharacterSize() / 2);

	background.setFillColor(sf::Color::Black);
	background.setSize(sf::Vector2f(windowSize.x, 62.f));
	background.setPosition(0.f,windowSize.y - background.getSize().y);
	background2.setFillColor(sf::Color::Blue);
	background2.setSize(sf::Vector2f(windowSize.x / 1.5 + 10,42.f));
	background2.setPosition(topCenter);
	background2.setOrigin(background2.getSize().x / 2, background2.getSize().y / 2);

	bossHealthBar.setFillColor(sf::Color::Red);
	bossHealthBar.setSize(sf::Vector2f(windowSize.x / 1.5,32.f));
	bossHealthBar.setPosition(sf::Vector2f(background2.getPosition().x  - (bossHealthBar.getSize().x/ 2), background2.getPosition().y - (bossHealthBar.getSize().y  / 2)));
	//bossHealthBar.setOrigin(bossHealthBar.getSize().x / 2, bossHealthBar.getSize().y / 2);
	bossHealthBarW = bossHealthBar.getSize().x;
}

void Hud::setHealth(int Health)
{
	Text_Health.setString("Health: " + std::to_string(Health));
}

void Hud::setLives(int Lives)
{
	Text_Lives.setString("Lives: " + std::to_string(Lives));
}

void Hud::setBossHealth(int Health)
{
	bossMaxHealth = Health;
}

void Hud::updateBossHealth(int Health)
{
	if (Health < 0) {
		Health = 0;
	}
	Text_BossHealth.setString(std::to_string(Health));
 	float fDamage = (bossMaxHealth - Health);
	float fDamagePercentage  = fDamage / bossMaxHealth;
	float fPercentage;				//Percentage damage to be removed
	float barW;	//New Width for health bar

	//calculate damage
	fPercentage = (bossHealthBarW / fDamagePercentage);
	barW = bossHealthBarW - (bossHealthBarW * fDamagePercentage);
	std::cout << fPercentage << std::endl;

	bossHealthBar.setSize(sf::Vector2f(barW, bossHealthBar.getSize().y));
}

void Hud::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background,states);
	target.draw(background2,states);
	target.draw(bossHealthBar,states);
	
	target.draw(Text_Health,states);
	target.draw(Text_Lives,states);
	target.draw(Text_BossHealth,states);
}