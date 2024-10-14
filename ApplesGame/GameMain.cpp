#include <SFML/Graphics.hpp>
#include "Game.h"
#include "const.h"
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ArkanoidGame!");
	{
		Game game;
		game.InitGame();
		Clock clock;
		float lastTime = clock.getElapsedTime().asSeconds();
		while (window.isOpen())
		{
			float currentTime = clock.getElapsedTime().asSeconds();
			float deltaTime = currentTime - lastTime;
			lastTime = currentTime;
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}

			game.UpdateGame(deltaTime);
			window.clear(Color(100, 100, 100));
			game.DrawGame(window);
			window.display();
		}
	}
}