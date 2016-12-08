#include "Engine.h"

Engine::Engine(): gameWindow(),snake(world.getBlockSize()),world(Vector2u(800,600))
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

	while (gameWindow.isOpen())
	{
		draw();
		input();
		update();
		restartClock();
	}

}

Time Engine::getElapsed()
{
	return elapsed;
}

void Engine::restartClock()
{
	elapsed += clock.restart();
}

Engine::~Engine()
{
}

void Engine::update()
{
		snake.update();
		world.update(snake);
		if (snake.hasLost())
			snake.reset();
}