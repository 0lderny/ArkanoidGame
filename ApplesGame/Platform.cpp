#include "Platform.h"

Platform::Platform()
{
	reset();

	assert(tPlatform.loadFromFile(RESOURCES + "\\wall_block_64_0.png"));
	sPlatform.setTexture(tPlatform);
	setSpriteSize(sPlatform, size, size);
	setSpriteRelativeOrigin(sPlatform, 0.5f, 0.5f);
}

void Platform::reset()
{
	start = false;
	position.x = SCREEN_SIZE / 2.f;
	position.y = SCREEN_SIZE + size / 3.f;
}

void Platform::move(float deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::A) && position.x - size / 2.f > 0)
	{
		position.x -= speed * deltaTime; start = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && position.x + size / 2.f < SCREEN_SIZE)
	{
		position.x += speed * deltaTime; start = true;
	}
	sPlatform.setPosition(position.x, position.y);
}

void Platform::draw(RenderWindow& window)
{
	sPlatform.setPosition(position.x, position.y);
	window.draw(sPlatform);
}

bool Platform::isStart()
{
	return start;
}