#include "Engine.h"

Engine::Engine()
{
	//Pobiera rozdzielczosc ekranu, tworzy okno gry
	Vector2f resolution;
	resolution.x = 800;
	resolution.y = 600;

	gameWindow.create(VideoMode(resolution.x, resolution.y), "Snake Game");

	//£aduje teksturê t³a
	gameBackgroudTexture.loadFromFile("data/background.png");
	gameBackgroudSprite.setTexture(gameBackgroudTexture);
}

void Engine::start()
{
	Clock clock;

	while (gameWindow.isOpen())
	{
		//Restart zegara i przypisanie czasu do time
		Time time = clock.restart();

		float timeAsSeconds = time.asSeconds();

		//input();
		//update(timeAsSeconds);
		draw();
	}

}

Engine::~Engine()
{
}