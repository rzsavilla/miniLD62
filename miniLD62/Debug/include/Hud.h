#ifndef HUD_H
#define HUD_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <Resources_Text.h>

class Hud: public sf::Drawable
{
public:
	Hud();

	void initialize(sf::Vector2u windowSize, Resources_Text& resources);

	void setHealth(int Health);
	void setLives(int Lives);
	void setBossHealth(int Health);
	void setMana(int Mana);
	void updateBossHealth(int Health);
	void updatePlayerHealth(int Health);
	void updatePlayerMana(int Mana);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Text Text_Health;
	sf::Text Text_Lives;
	sf::Text Text_BossHealth;
	sf::RectangleShape background;			//bottom bar

	sf::Texture Texture_Health;				//Health bar
	sf::Texture Texture_Mana;

	//Boss Health Bar
	float bossHealthBarW;					//Original Width of Health bar
	int bossMaxHealth;
	sf::RectangleShape bossHealthBar;
	sf::RectangleShape background2;			//Boss Health Background

	//Player Health Bar
	float PlayerHealthBarW;
	int PlayerMaxHealth;
	sf::RectangleShape PlayerHealthBar;
	sf::RectangleShape background3;

	//Player Mana Bar
	float ManaBarW;							//Original Width
	int iMana;
	int MaxMana;
	sf::RectangleShape(ManaBar);
};

#endif
