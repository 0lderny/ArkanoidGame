#pragma once
#include <SFML/Graphics.hpp>

struct Position
{
	float x;
	float y;
};

void setSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);

void setSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);

bool checkCollide(Position ballPos, float ballSize, Position platPos, float platSize);