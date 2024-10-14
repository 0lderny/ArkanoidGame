#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"

struct Position
{
	float x;
	float y;
};

void setSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);

void setSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);

bool isCollideX(const Position& ballPos, const float& ballSize);

bool isCollideY(const Position& ballPos, const float& ballSize);

bool isCollidePlatformX(const Position& ballPos, const float& ballSize, const Position& platformPos, const float& platformSize);

bool isCollidePlatformY(const Position& ballPos, const float& ballSize, const Position& platformPos, const float& platformSize);

bool isCollideBlockX(const Position& ballPos, const float& ballSize, const Position& blockPos, const float& blockSize);

bool isCollideBlockY(const Position& ballPos, const float& ballSize, const Position& blockPos, const float& blockSize);


