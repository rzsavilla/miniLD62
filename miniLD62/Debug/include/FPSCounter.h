#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include <SFML/System/Clock.hpp>
#include <iostream>

class FPSCounter
{
public:
	FPSCounter();
	void update();
	int getFPS();
private:
	sf::Clock timer;
	sf::Time current;
	sf::Time elapsed;
	int iCounter;			//Total Frames
	int iFPS;
};

#endif