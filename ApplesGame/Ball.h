#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "const.h"
using namespace sf;

class Ball
{
	CircleShape ball;
	Position position;
	Vector2f direction;
	float speed = 200;
	int radius = 10;

public:
	Ball();
	Position getPosition() const { return position; }
	float getX() const { return position.x; }
	float getY() const { return position.y; }
	float getSpeed() const { return speed; }
	int getRadius() const { return radius; }

	void reset();
	void move(float deltaTime);
	void changeX();
	void changeY();
	void draw(RenderWindow& window);
};