#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <cassert>
#include "Math.h"
#include "const.h"
using namespace sf;

class Platform final : public GameObject
{
	Texture tPlatform;
	Sprite sPlatform;
	float m_speed = 600;
	bool start = false;

public:
	Platform();
	float getSpeed() const { return m_speed; }

	void reset() override;
	void move(float deltaTime) override;
	void draw(RenderWindow& window) override;
	bool isStart();
};
