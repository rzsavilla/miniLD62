#include <FPSCounter.h>

FPSCounter::FPSCounter()
{
	//Initialize
	iCounter = 0;
	iFPS = 0;
}

void FPSCounter::update()
{
	if (timer.getElapsedTime().asSeconds() > 1.f)
	{
		iFPS = iCounter;
		iCounter = 0;		//Reset Counter
		timer.restart();	//Reset timer;
	}
	iCounter++;
}

int FPSCounter::getFPS()
{
	return iFPS;
}