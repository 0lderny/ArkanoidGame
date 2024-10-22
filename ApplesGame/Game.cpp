#include "Game.h"

Game::Game()
	: platform(), ball(), block(), rockBlock(),
	playText("Play", 450, 250, 100), exitText("Exit", 440, 400, 100),
	winText("You won!", 330, 75, 125), loseText("You lost", 350, 75, 125),
	playAgainText("Play again", 410, 250, 75), mainMenuText("Main Menu", 400, 350, 75) {
}

void Game::InitGame()
{
	
}

void Game::UpdateGame(float deltaTime)
{
	if (gameState == MainMenu)
	{
		if (sf::Keyboard::isKeyPressed(Keyboard::Enter))
			gameState = Start;
		else if (sf::Keyboard::isKeyPressed(Keyboard::Escape))
			gameState = Exit;
	}

	else if (gameState == Start)
	{
		platform.move(deltaTime);
		if (platform.isStart())
			ball.move(deltaTime);

		if (isCollideX(ball.getPosition(), ball.getSize()))
			ball.changeDirection(true);
		if (isCollideY(ball.getPosition(), ball.getSize()))
			ball.changeDirection(false);

		if (isCollidePlatformX(ball.getPosition(), ball.getSize(), platform.getPosition(), platform.getSize()))
			ball.changeDirection(true);
		if (isCollidePlatformY(ball.getPosition(), ball.getSize(), platform.getPosition(), platform.getSize()))
			ball.changeDirection(false);

		for (int i = 0; i < rockBlock.getNumBlocks(); ++i)
		{
			if (isCollideBlockX(ball.getPosition(), ball.getSize(), rockBlock.getPosition(i), rockBlock.getSize()))
			{
				ball.changeDirection(true);
				rockBlock.remove(i);
			}
			if (isCollideBlockY(ball.getPosition(), ball.getSize(), rockBlock.getPosition(i), rockBlock.getSize()))
			{
				ball.changeDirection(false);
				rockBlock.remove(i);
			}
		}

		for (int i = 0; i < block.getNumBlocks(); ++i)
		{
			if (isCollideBlockX(ball.getPosition(), ball.getSize(), block.getPosition(i), block.getSize()))
			{
				ball.changeDirection(true);
				block.remove(i);
			}
			if (isCollideBlockY(ball.getPosition(), ball.getSize(), block.getPosition(i), block.getSize()))
			{
				ball.changeDirection(false);
				block.remove(i);
			}
		}
			
		if ((ball.getY() > SCREEN_HEIGHT + 100))
		{
			gameResult = false;
			gameState = GameOver;
		}
		else if (block.noBlocks() && rockBlock.noBlocks())
		{
			gameResult = true;
			gameState = GameOver;
		}
	}

	else if (gameState == GameOver)
	{
		if (gameResult)
		{

		}
		else if (!gameResult)
		{

		}
	}
}

void Game::RestartGame()
{
	platform.reset();
	ball.reset();
	block.reset();
	rockBlock.reset();
}

void Game::DrawGame(RenderWindow& window)
{
	if (gameState == MainMenu)
	{
		playText.draw(window);
		exitText.draw(window);
	}
	else if (gameState == Start)
	{
		platform.draw(window);
		ball.draw(window);
		block.draw(window);
		rockBlock.draw(window);
	}
	else if (gameState == GameOver)
	{
		if (gameResult)
			winText.draw(window);
		else
			loseText.draw(window);

		playAgainText.draw(window);
		mainMenuText.draw(window);

		if (sf::Keyboard::isKeyPressed(Keyboard::Enter))
		{
			RestartGame();
			gameState = Start;
		}
		else if (sf::Keyboard::isKeyPressed(Keyboard::Escape))
			gameState = MainMenu;
			
	}
	else if (gameState == Exit)
	{
		window.close();
	}
}