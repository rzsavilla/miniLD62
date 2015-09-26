#ifndef ANIMATEDRECT_H
#define ANIMATEDRECT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Animation.h>

class AnimatedRect: public sf::RectangleShape
{
public:
	AnimatedRect();

	void setAnimation(Animation& anim);
	void play();						//Play animation
	void stop();						//Stop animation on current frame
	void reset();						//Return animation to first frame
	void setFrame(int i);				//Set animation to specific frame
	void loopAnimation(bool Loop);

	bool isPlaying();					//Returns bPlaying
	bool isFinished();					//Animation completed
	void animate();						//Updates animation
private:
	int iFrame;							//Current Frame
	bool bPlaying;						//Determines if animation is playing
	bool bLoop;							//If animation loops
	bool frameUpdated;					//If frame has been updated
	bool bFinished;						//Completed a full animation cycle
	Animation animation;
	sf::Clock timer;					//Animation timer, determines speed of animation						
};
#endif