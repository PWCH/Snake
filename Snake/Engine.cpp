#include "Engine.h"

Engine::Engine(): gameWindow(),snake(),world(Vector2u(800,600))
{
	//Pobiera rozdzielczosc ekranu, tworzy okno gry
	Vector2u resolution;
	resolution.x = 800;
	resolution.y = 600;

	gameWindow.create(VideoMode(resolution.x, resolution.y), "Snake Game");

	//�aduje tekstur� t�a
	gameBackgroudTexture.loadFromFile("data/background.png");
	gameBackgroudSprite.setTexture(gameBackgroudTexture);
	textbox.setup(5, 14, 250, Vector2f(225, 0));
	live = "Liczba zyc: " + snake.getLives();
	textbox.add(live);
	score = "Wynik: " + snake.getScore();
	textbox.add(score);
	textbox.render(gameWindow);
	//cout << snake.getLives();
	snake.reset();
}

void Engine::start()
{
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
