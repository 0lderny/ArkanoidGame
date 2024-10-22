#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Platform.h"
#include "Ball.h"
#include "Block.h"
#include "RockBlock.h"
#include "Text.h"

class Game
{
	enum GameState
	{
		MainMenu,
		Start,
		GameOver,
		Pause,
		Exit, 
		Settings
	};
	
	Platform platform;
	Ball ball;
	Block block;
	RockBlock rockBlock;
	
	GameState gameState = MainMenu;
	bool gameResult = 0;

	Texts playText;
	Texts exitText;
	Texts winText;
	Texts loseText;
	Texts playAgainText;
	Texts mainMenuText;

public:
	Game();
	void InitGame();
	void UpdateGame(float deltaTime);
	void RestartGame();
	void DrawGame(RenderWindow& window);
};