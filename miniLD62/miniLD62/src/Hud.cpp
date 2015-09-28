#include <Hud.h>
#include <iostream>

Hud::Hud()
{

}
 
void Hud::initialize(sf::Vector2u windowSize, Resources_Text& resources)
{
	Texture_Health.loadFromFile("assets/textures/Health_Bar.png");
	Texture_Mana.loadFromFile("assets/textures/Mana_Bar.png");

	float fOffsetX = 50;		//For Positioning
	float fOffsetY = 40;
	sf::Vector2f bottomLeft(fOffsetX,windowSize.y - fOffsetY);
	sf::Vector2f bottomRight(windowSize.x - fOffsetX * 2,windowSize.y - fOffsetY);
	sf::Vector2f topCenter(windowSize.x / 2, fOffsetY);

	//resources.setText(Text_Health,resources.arial,sf::Color::White, 20.f,bottomLeft,"Health: ");
	//resources.setText(Text_Lives,resources.arial,sf::Color::White, 20.f,bottomRight,"Health: ");
	//resources.setText(Text_BossHealth,resources.arial,sf::Color::White, 20.f,topCenter,"1000");
	Text_BossHealth.setOrigin(Text_BossHealth.getGlobalBounds().width / 2 , Text_BossHealth.getCharacterSize() / 2);

	background.setFillColor(sf::Color::Black);
	background.setSize(sf::Vector2f(windowSize.x, 62.f));
	background.setPosition(0.f,windowSize.y - background.getSize().y);
	background2.setFillColor(sf::Color::Black);
	background2.setSize(sf::Vector2f(windowSize.x / 1.5 + 10,42.f));
	background2.setPosition(topCenter);
	background2.setOrigin(background2.getSize().x / 2, background2.getSize().y / 2);

	bossHealthBar.setTexture(&Texture_Health);
	bossHealthBar.setFillColor(sf::Color::Red);
	bossHealthBar.setSize(sf::Vector2f(windowSize.x / 1.5,32.f));
	bossHealthBar.setPosition(sf::Vector2f(background2.getPosition().x  - (bossHealthBar.getSize().x/ 2), background2.getPosition().y - (bossHealthBar.getSize().y  / 2)));
	//bossHealthBar.setOrigin(bossHealthBar.getSize().x / 2, bossHealthBar.getSize().y / 2);
	bossHealthBarW = bossHealthBar.getSize().x;

	PlayerHealthBar.setTexture(&Texture_Health);
	PlayerHealthBar.setSize(sf::Vector2f(150.f,20.f));
	PlayerHealthBar.setPosition(10.f,430.f);
	PlayerHealthBarW = PlayerHealthBar.getSize().x;

	ManaBar.setTexture(&Texture_Mana);
	ManaBar.setSize(sf::Vector2f(150.f,20.f));
	ManaBar.setPosition(10.f,455.f);
	ManaBarW = ManaBar.getSize().x;
}

void Hud::setHealth(int Health)
{
	PlayerMaxHealth = Health;
}

void Hud::setBossHealth(int Health)
{
	bossMaxHealth = Health;
}

void Hud::setMana(int Mana)
{
	MaxMana = Mana;
	iMana = Mana;
}

void Hud::updateBossHealth(int Health)
{
	if (Health < 0) {
		Health = 0;
	}
	//Text_BossHealth.setString(std::to_string(Health));
 	float fDamage = (bossMaxHealth - Health);
	float fDamagePercentage  = fDamage / bossMaxHealth;
	float fPercentage;				//Percentage damage to be removed
	float barW;	//New Width for health bar

	//calculate damage
	fPercentage = (bossHealthBarW / fDamagePercentage);
	barW = bossHealthBarW - (bossHealthBarW * fDamagePercentage);
	bossHealthBar.setSize(sf::Vector2f(barW, bossHealthBar.getSize().y));
}

void Hud::updatePlayerHealth(int Health)
{
	if (Health < 0) {
		Health = 0;
	} else if (Health > bossMaxHealth)
		Health = bossMaxHealth;
 	float fDamage = (PlayerMaxHealth - Health);
	float fDamagePercentage  = fDamage / PlayerMaxHealth;
	float fPercentage;				//Percentage damage to be removed
	float barW;	//New Width for health bar
	
	//calculate damage
	fPercentage = (PlayerHealthBarW / fDamagePercentage);
	barW = PlayerHealthBarW - (PlayerHealthBarW * fDamagePercentage);

	PlayerHealthBar.setSize(sf::Vector2f(barW, PlayerHealthBar.getSize().y));
}

void Hud::updatePlayerMana(int Mana)
{
	if (Mana < 0) {
		Mana = 0;
	}
 	float fDamage = (MaxMana - Mana);
	float fDamagePercentage  = fDamage / MaxMana;
	float fPercentage;				//Percentage damage to be removed
	float barW;	//New Width for health bar

	//calculate damage
	fPercentage = (ManaBarW / fDamagePercentage);
	barW = ManaBarW - (ManaBarW * fDamagePercentage);

	ManaBar.setSize(sf::Vector2f(barW, ManaBar.getSize().y));
}

void Hud::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//target.draw(background,states);
	target.draw(background2,states);
	target.draw(bossHealthBar,states);
	target.draw(PlayerHealthBar, states);
	target.draw(ManaBar, states);
	//target.draw(Text_Health,states);
	//target.draw(Text_Lives,states);
	//target.draw(Text_BossHealth,states);
}