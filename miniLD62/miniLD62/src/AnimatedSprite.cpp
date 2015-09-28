#include <AnimatedSprite.h>

AnimatedSprite::AnimatedSprite()
{
	iFrame = 0;
	bPlaying = false;
	bLoop = false;
	frameUpdated = false;
	bFinished = false;
}

void AnimatedSprite::setAnimation(Animation& anim)
{
	//reset();
	animation = anim;
	setTexture(animation.spriteSheet);
	setTextureRect(animation.getFrame(iFrame));
	setOrigin(getTextureRect().width / 2, getTextureRect().height / 2);
}

void AnimatedSprite::play()
{
	bPlaying = true;
	bFinished = false;
}
void AnimatedSprite::stop()
{
	bPlaying = false;
}
void AnimatedSprite::reset()
{
	frameUpdated = false;
	iFrame = 0;
}
void AnimatedSprite::setFrame(int i) 
{
	frameUpdated = false;
	iFrame = i;
}
void AnimatedSprite::loopAnimation(bool Loop)
{
	bLoop = Loop;
}

bool AnimatedSprite::isPlaying()
{
	return bPlaying;
}

bool AnimatedSprite::isFinished()
{
	return bFinished;
}


void AnimatedSprite::animate()
{
	if (!frameUpdated) {			//new texture set only when frame is changed
		setTextureRect(animation.getFrame(iFrame));
		frameUpdated = true;
	}
	if (bPlaying)
	{
		if (timer.getElapsedTime().asSeconds() > animation.getSpeed()) {
			//Change Frame
			if (iFrame <= animation.getFrameCount()) {
				iFrame++; //Next Frame
				timer.restart();
			} else {
				/*
				if (bLoop) {
					reset();		//Return to first frame
					timer.restart();
				} else {
					iFrame--;				//Return to previous frame
					bFinished = true;		//Animation Cycle has finished
					stop();					//Stop Animation
				}
				*/
			}

			if (iFrame >= animation.getFrameCount()) {
				if (bLoop) {
					reset();		//Return to first frame
					timer.restart();
				} else {
					iFrame--;				//Return to previous frame
					bFinished = true;		//Animation Cycle has finished
					stop();					//Stop Animation
				}
			}
			setTextureRect(animation.getFrame(iFrame));
			//frameUpdated = false;
		}
	}
}