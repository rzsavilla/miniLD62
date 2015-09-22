#ifndef ANIMATION_H
#define ANIMATION_H

/*
Stores frames/rect
and filename of the spritesheet used
*/

#include <SFML/Graphics.hpp>
#include <iostream>

class Animation
{
public:
	Animation();

	void setSpeed(float Speed);

	void setSpriteSheet(std::string filename);		//will load the texture for spriteSheet
	void setSpriteSheet(sf::Texture& texture);

	float getSpeed();
	int getFrameCount();
	sf::IntRect getFrame(int FrameNumber);

	void addFrame(sf::IntRect rect);										//Add a single frame
	void addFrames(sf::IntRect rect, int Number, sf::Vector2u size);		//Add Multiple frames	
	
	sf::Texture spriteSheet;
private:
	std::vector <sf::IntRect> frames;	//Stores frames
	float fSpeed;
};
#endif 
