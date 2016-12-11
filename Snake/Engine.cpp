#include "Engine.h"

Engine::Engine(): gameWindow(),snake(),world(Vector2u(800,600))
{
	//Pobiera rozdzielczosc ekranu, tworzy okno gry
	Vector2u resolution;
	resolution.x = 800;
	resolution.y = 600;

	gameWindow.create(VideoMode(resolution.x, resolution.y), "Snake Game");

	//£aduje teksturê t³a
	gameBackgroudTexture.loadFromFile("data/background.png");
	gameBackgroudSprite.setTexture(gameBackgroudTexture);
	scoreBox.setup(1, 20, 80, Vector2f(398, 0));
	liveBox.setup(1, 20, 85, Vector2f(313, 0));
	snake.reset();
}

void Engine::start()
{
	while (gameWindow.isOpen())
	{
		Event event;
		while (gameWindow.pollEvent(event))
		{
			// Zamykanie okna - exit
			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}
		input();
		draw();
		update();
		scoreBox.clear();
		liveBox.clear();
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
	//switch (menu)
	//{
	//	case(StateType::Intro):
	//		updateIntro();
	//		break;
	//	case(StateType::Game):
	//		updateGame();
	//		break;
	//	case(StateType::MainMenu):
	//		updateMenu();
	//		break;
	//	default:
	//		break;
	//}
	float timestep = 0.1f / snake.getSpeed();
	float timeInSec = elapsed.asSeconds();
	if (timeInSec >= timestep)
	{
		snake.update();
		world.update(snake);
		if (snake.hasLost())
			snake.reset();
		
	}
}
