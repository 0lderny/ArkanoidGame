#include "Ball.h"

Ball::Ball() : GameObject(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT - 25.f, 15)
{
	reset();

	ball.setFillColor(Color::White);
	ball.setOrigin(m_size, m_size);
	ball.setRadius(m_size);
}

void Ball::reset()
{
	m_position.x = SCREEN_WIDTH / 2.f;
	m_position.y = SCREEN_HEIGHT - 30.f;
	ball.setPosition(m_position.x, m_position.y);
	direction = { m_speed, m_speed };
}

void Ball::move(float deltaTime)
{
	m_position.x += direction.x * deltaTime;
	m_position.y += direction.y * deltaTime;
	ball.setPosition(m_position.x, m_position.y);
}

void Ball::changeDirection(bool dir)
{
	if (dir)
		direction.x = -direction.x;
	else
		direction.y = -direction.y;
}

void Ball::draw(RenderWindow& window)
{
	ball.setPosition(m_position.x, m_position.y);
	window.draw(ball);
}