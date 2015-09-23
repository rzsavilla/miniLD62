#include <AnimatedSprite.h>

AnimatedSprite::AnimatedSprite()
{
	iFrame = 0;
	bPlaying = false;
	bLoop = false;
	frameUpdated = false;
}

void AnimatedSprite::setAnimation(Animation& anim)
{
	//reset();
	animation = anim;
	setTexture(animation.spriteSheet);
	setTextureRect(animation.getFrame(iFrame));
	//setOrigin(getTextureRect().width / 2, getTextureRect().height / 2);
}

void AnimatedSprite::play()
{
	timer.restart();
	bPlaying = true;
}
void AnimatedSprite::stop()
{
	bPlaying = false;
}
void AnimatedSprite::reset()
{
	iFrame = 0;
}
void AnimatedSprite::setFrame(int i) 
{
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

void AnimatedSprite::animate()
{
	if (!frameUpdated) {			//new texture set only when frame is changed
		setTextureRect(animation.getFrame(iFrame));
		setOrigin(getTextureRect().width / 2, getTextureRect().height / 2);
		frameUpdated = true;
	}
	if (bPlaying)
	{
		if (animation.getFrameCount() >= 1) {					//Will only animate if there is more than 1 frame
			sf::Time elapsed = timer.getElapsedTime();	
			if (elapsed.asSeconds() > animation.getSpeed()) {
				//Change frame
				iFrame++;
				if (iFrame >= animation.getFrameCount()) {
					reset();						//Return to first frame
					if (!bLoop) {					//Animation does not loop
						stop();							//Stop animation
					}
				}
				timer.restart();
				frameUpdated = false;				//Frame needs to be updated
			}
		}
	}
}
