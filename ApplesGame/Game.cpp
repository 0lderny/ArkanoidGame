#include "Game.h"

void Game::InitGame()
{

}

void Game::UpdateGame(float deltaTime)
{
	platform.move(deltaTime);
	if (platform.isStart())
		ball.move(deltaTime);
	if (ball.getX() + ball.getRadius() > SCREEN_SIZE || ball.getX() - ball.getRadius() < 0)
		ball.changeX();
	if (checkCollide(ball.getPosition(), ball.getRadius(), platform.getPosition(), platform.getSize()) || ball.getY() - ball.getRadius() < 0)
		ball.changeY();
	if (ball.getY() > SCREEN_SIZE + 100)
		RestartGame();
}

void Game::RestartGame()
{
	platform.reset();
	ball.reset();
}

void Game::DrawGame(RenderWindow& window)
{
	platform.draw(window);
	ball.draw(window);
}