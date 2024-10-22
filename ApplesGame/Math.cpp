#include "Math.h"

int getRandomNumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void setSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight)
{
	sf::FloatRect spriteRect = sprite.getLocalBounds();
	sf::Vector2f scale = { desiredWidth / spriteRect.width, desiredHeight / spriteRect.height };
	sprite.setScale(scale);
}

void setSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY)
{
	sf::FloatRect spriteRect = sprite.getLocalBounds();
	sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
}

bool isCollideX(const Position& ballPos, const float& ballSize)
{
	if ((ballPos.x + ballSize / 2.f) > SCREEN_WIDTH || (ballPos.x - ballSize / 2.f) < 0)
		return true;
	else return false;
}
bool isCollideY(const Position& ballPos, const float& ballSize)
{
	if (ballPos.y - ballSize / 2.f < 0)
		return true;
	else return false;
}

bool isCollidePlatformX(const Position& ballPos, const float& ballSize, const Position& platformPos, const float& platformSize)
{
	if ((ballPos.x + ballSize / 2.f) > (platformPos.x - platformSize / 2.f) && 
		(ballPos.x - ballSize / 2.f) < (platformPos.x + platformSize / 2.f) && 
		(ballPos.y + ballSize / 2.f) > (platformPos.y - platformSize / 2.f) && 
		(ballPos.y - ballSize / 2.f) < (platformPos.y + platformSize / 2.f))   
		if (ballPos.x < platformPos.x - platformSize / 2.f || ballPos.x > platformPos.x + platformSize / 2.f)
			return true;
	return false;
}
bool isCollidePlatformY(const Position& ballPos, const float& ballSize, const Position& platformPos, const float& platformSize)
{
	if ((ballPos.y + ballSize / 2.f) >= (platformPos.y - platformSize / 2.f) &&
		(ballPos.y - ballSize / 2.f) < (platformPos.y + platformSize / 2.f) && 
		(ballPos.x + ballSize / 2.f) > (platformPos.x - platformSize / 2.f) &&  
		(ballPos.x - ballSize / 2.f) < (platformPos.x + platformSize / 2.f))
		if (ballPos.y < platformPos.y - platformSize / 2.f || ballPos.y > platformPos.y + platformSize / 2.f)
		return true;
	return false;
}

bool isCollideBlockX(const Position& ballPos, const float& ballSize, const Position& blockPos, const float& blockSize)
{
	if ((ballPos.x + ballSize / 2.f) >= (blockPos.x - blockSize / 2.f) &&
		(ballPos.x - ballSize / 2.f) <= (blockPos.x + blockSize / 2.f) &&
		(ballPos.y + ballSize / 2.f) >= (blockPos.y - blockSize / 2.f) &&
		(ballPos.y - ballSize / 2.f) <= (blockPos.y + blockSize / 2.f))
		if (ballPos.x < blockPos.x - blockSize / 2.f || ballPos.x > blockPos.x + blockSize / 2.f)
			return true;
	return false;
}
bool isCollideBlockY(const Position& ballPos, const float& ballSize, const Position& blockPos, const float& blockSize)
{
	if ((ballPos.y + ballSize / 2.f) >= (blockPos.y - blockSize / 2.f) &&
		(ballPos.y - ballSize / 2.f) <= (blockPos.y + blockSize / 2.f) &&
		(ballPos.x + ballSize / 2.f) >= (blockPos.x - blockSize / 2.f) &&
		(ballPos.x - ballSize / 2.f) <= (blockPos.x + blockSize / 2.f))
		if (ballPos.y < blockPos.y - blockSize / 2.f || ballPos.y > blockPos.y + blockSize / 2.f)
			return true;
	return false;
}


