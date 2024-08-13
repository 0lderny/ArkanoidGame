#include "Ball.h"

Ball::Ball()
{
	reset();

	ball.setFillColor(Color::White);
	ball.setOrigin(radius, radius);
	ball.setRadius(radius);
}

void Ball::reset()
{
	position.x = SCREEN_SIZE / 2.f;
	position.y = SCREEN_SIZE - 25.f;
	ball.setPosition(position.x, position.y);
	direction = { speed, -speed };
}

void Ball::move(float deltaTime)
{
	position.x += direction.x * deltaTime;
	position.y += direction.y * deltaTime;
	ball.setPosition(position.x, position.y);
}

void Ball::changeX()
{
	direction.x = -direction.x;
}

void Ball::changeY()
{
	direction.y = -direction.y;
}

void Ball::draw(RenderWindow& window)
{
	ball.setPosition(position.x, position.y);
	window.draw(ball);
}