#include "Platform.h"

Platform::Platform() : GameObject(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT + m_size / 3.f, 200)
{
	reset();

	assert(tPlatform.loadFromFile(RESOURCES + "\\wall_block_64_0.png"));
	sPlatform.setTexture(tPlatform);
	setSpriteSize(sPlatform, m_size, m_size);
	setSpriteRelativeOrigin(sPlatform, 0.5f, 0.5f);
}

void Platform::reset()
{
	start = false;
	m_position.x = SCREEN_WIDTH / 2.f;
	m_position.y = SCREEN_HEIGHT + m_size / 2.5f;
}

void Platform::move(float deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::A) && m_position.x - m_size / 2.f > 0)
	{
		m_position.x -= m_speed * deltaTime; start = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && m_position.x + m_size / 2.f < SCREEN_WIDTH)
	{
		m_position.x += m_speed * deltaTime; start = true;
	}
	sPlatform.setPosition(m_position.x, m_position.y);
}

void Platform::draw(RenderWindow& window)
{
	sPlatform.setPosition(m_position.x, m_position.y);
	window.draw(sPlatform);
}

bool Platform::isStart()
{
	return start;
}