#include <Animation.h>

Animation::Animation()
{
	fSpeed = 0.5f;
}

void Animation::setSpeed(float Speed)
{
	fSpeed = Speed;
}

void Animation::setSpriteSheet(std::string filename)
{
	if (!spriteSheet.loadFromFile("assets/textures/" + filename)) {
		std::cout << "Could not load sprite sheet\n";
	}
}

void Animation::setSpriteSheet(sf::Texture& texture)
{
	spriteSheet = texture;
}

float Animation::getSpeed()
{
	return fSpeed;
}

int Animation::getFrameCount()
{
	return frames.size();
}

sf::IntRect Animation::getFrame(int FrameNumber) 
{
	return frames[FrameNumber];
}

void Animation::addFrame(sf::IntRect rect)
{
	frames.push_back(rect);
}
void Animation::addFrames(sf::IntRect rect, int Number, sf::Vector2u size)
{
	int X = 0, Y = 0;
	int yCounter = 0;
	int xCounter = 0;
	for (int i = 0; i < Number; i++) {					//Counts number of frames added
		X = (xCounter * rect.width);
		if (X >= size.x) {
			yCounter++;
			xCounter = 0;
		} else {
			xCounter++;
		}
		Y = yCounter * rect.height;

		X += rect.left;
		Y += rect.top;
		frames.push_back(sf::IntRect(X,Y,rect.width, rect.height));		//Add frame
	}
}