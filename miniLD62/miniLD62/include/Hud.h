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
	void updateBossHealth(int Health);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Text Text_Health;
	sf::Text Text_Lives;
	sf::Text Text_BossHealth;
	sf::RectangleShape background;			//bottom bar

	float bossHealthBarW;					//Original Width of Health bar
	int bossMaxHealth;
	sf::RectangleShape bossHealthBar;
	sf::RectangleShape background2;			//Boss Health Background
};

#endif
