#pragma once
#include <SFML/Graphics.hpp>
#include <cassert>
#include "Math.h"
#include "const.h"
using namespace sf;

class Platform
{
	Texture tPlatform;
	Sprite sPlatform;
	Position position;
	float speed = 333;
	int size = 100;
	bool start = false;

public:
	Platform();
	Position getPosition() const { return position; }
	float getX() const { return position.x; }
	float getY() const { return position.y; }
	float getSpeed() const { return speed; }
	int getSize() const { return size; }

	void reset();
	void move(float deltaTime);
	void draw(RenderWindow& window);
	bool isStart();
};
