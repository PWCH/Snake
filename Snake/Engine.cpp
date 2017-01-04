#include "Engine.h"

Engine::Engine(): snake(), world(Vector2u(800, 600))
{
	//Pobiera rozdzielczosc ekranu, tworzy okno gry
	Vector2u resolution;
	resolution.x = 800;
	resolution.y = 600;

	gameWindow.create(VideoMode(resolution.x, resolution.y), "Snake Game");

	//£aduje teksturê t³a
	gameBackgroudTexture.loadFromFile("data/background.png");
	gameBackgroudSprite.setTexture(gameBackgroudTexture);
	scoreBox.setup(1, 25, 180, Vector2f(390, 0));
	liveBox.setup(1, 25, 190, Vector2f(200, 0));
	gameoverBox.setup(3, 30, 150, Vector2f(resolution.x / 2 - 50, resolution.y / 2 - 50));
	snake.reset();
}

void Engine::start(RenderWindow &menuWindow)
{
	while (menuWindow.isOpen())
	{
		input();
		draw();
		//if (!pause)
		//{
			update();
		//};
		scoreBox.clear();
		liveBox.clear();
		restartClock();
		if (!(gameWindow.isOpen()))
			break;
	}
	menuWindow.display();
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
	float timestep = 1.0f / snake.getSpeed();
	float timeInSec = elapsed.asSeconds();
	if (timeInSec >= timestep)
	{
		snake.update();
		world.update(snake);
		if (snake.hasLost())
		{
			gameWindow.close();
		}
	}
}
