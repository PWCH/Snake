#include "Engine.h"

Engine::Engine(): gameWindow(),snake(world.getBlockSize()),world(Vector2u(800,600))
{
	//Pobiera rozdzielczosc ekranu, tworzy okno gry
	Vector2u resolution;
	resolution.x = 800;
	resolution.y = 600;

	gameWindow.create(VideoMode(resolution.x, resolution.y), "Snake Game");

	//£aduje teksturê t³a
	gameBackgroudTexture.loadFromFile("data/background.png");
	gameBackgroudSprite.setTexture(gameBackgroudTexture);
}

void Engine::start()
{
	snake.reset();
	while (gameWindow.isOpen())
	{
		input();
		draw();
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
	float timestep = 0.1 / snake.getSpeed();
	float timeInSec = elapsed.asMilliseconds();
	if (timeInSec >= timestep)
	{
		snake.update();
		world.update(snake);
		if (snake.hasLost())
			snake.reset();
	}
}
