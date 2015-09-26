#include <AnimatedRect.h>

AnimatedRect::AnimatedRect()
{
	iFrame = 0;
	bPlaying = false;
	bLoop = false;
	frameUpdated = false;
	bFinished = false;
}

void AnimatedRect::setAnimation(Animation& anim)
{
	//reset();
	animation = anim;
	setTexture(animation.getTextureAddress());
	setTextureRect(animation.getFrame(iFrame));
	setOrigin(getTextureRect().width / 2, getTextureRect().height / 2);
}

void AnimatedRect::play()
{
	bPlaying = true;
	bFinished = false;
}
void AnimatedRect::stop()
{
	bPlaying = false;
}
void AnimatedRect::reset()
{
	iFrame = 0;
}
void AnimatedRect::setFrame(int i) 
{
	iFrame = i;
}
void AnimatedRect::loopAnimation(bool Loop)
{
	bLoop = Loop;
}

bool AnimatedRect::isPlaying()
{
	return bPlaying;
}

bool AnimatedRect::isFinished()
{
	return bFinished;
}


void AnimatedRect::animate()
{
	if (!frameUpdated) {			//new texture set only when frame is changed
		setTextureRect(animation.getFrame(iFrame));
		setSize(sf::Vector2f(animation.getFrame(iFrame).width,animation.getFrame(iFrame).height));
		setOrigin(getSize().x / 2, getSize().y / 2);
		frameUpdated = true;
	}
	if (bPlaying)
	{
		if (timer.getElapsedTime().asSeconds() > animation.getSpeed()) {
			//Change Frame
			if (iFrame <= animation.getFrameCount()) {
				iFrame++; //Next Frame
				std::cout << "Next Frame\n";
				timer.restart();
			} else {
				if (bLoop) {
					reset();		//Return to first frame
					std::cout << "Loop Frame\n";
					timer.restart();
				} else {
					iFrame--;				//Return to previous frame
					bFinished = true;		//Animation Cycle has finished
					std::cout << "End\n";
					stop();					//Stop Animation
				}
			}

			if (iFrame >= animation.getFrameCount()) {
				if (bLoop) {
					reset();		//Return to first frame
					std::cout << "Loop Frame\n";
					timer.restart();
				} else {
					iFrame--;				//Return to previous frame
					bFinished = true;		//Animation Cycle has finished
					std::cout << "End\n";
					stop();					//Stop Animation
				}
			}
			frameUpdated = false;
		}
		//std::cout << iFrame << std::endl;
			/*
			if (!bFinished) {
				if (iFrame < animation.getFrameCount()) {
					if (elapsed.asSeconds() > animation.getSpeed()) {
						//Next frame
						iFrame++;
						frameUpdated = false;				//Frame needs to be updated
						timer.restart();
					}
				} else {
					if (bLoop) {
						reset();
						play();
					} else {
						reset();
						bFinished = true;
					}


				} */
	}
}