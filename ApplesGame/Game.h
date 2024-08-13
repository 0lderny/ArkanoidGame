#pragma once
#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "Ball.h"
#include "Math.h"

class Game
{
	Platform platform;
	Ball ball;

public:
	void InitGame();
	void UpdateGame(float deltaTime);
	void RestartGame();
	void DrawGame(RenderWindow& window);
};