#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "const.h"
using namespace sf;

class GameObject
{
protected:
	Position m_position;
	int m_size;

public:
	GameObject(int x, int y, int size);
	GameObject(int size);
	Position getPosition() const { return m_position; }
	float getX() const { return m_position.x; }
	float getY() const { return m_position.y; }
	int getSize() const { return m_size; }

	virtual void reset() = 0;
	virtual void move(float deltaTime) = 0;
	virtual void draw(RenderWindow& window) = 0;
};
