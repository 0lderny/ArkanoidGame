#include "Math.h"

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

bool checkCollide(Position ballPos, float ballSize, Position platPos, float platSize)
{
	float squareDistance = (pow(platPos.x - ballPos.x, 2)) + (pow(platPos.y - ballPos.y, 2));
	float squareRadiusSum = (pow(ballSize + platSize, 2)) / 4;
	return (squareDistance <= squareRadiusSum);
}