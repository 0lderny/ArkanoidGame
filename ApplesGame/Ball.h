#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Math.h"
#include "const.h"
using namespace sf;

class Ball final : public GameObject
{
	CircleShape ball;
	Vector2f direction;
	float m_speed = 500;

public:
	Ball();
	float getSpeed() const { return m_speed; }

	void reset() override;
	void move(float deltaTime) override;
	void changeDirection(bool dir);
	void draw(RenderWindow& window) override;
};