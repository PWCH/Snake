#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	//switch (menu)
	//{
	//case(StateType::Intro):
	//	updateIntro();
	//	break;
	//case(StateType::Game):
	//	updateGame();
	//	break;
	//case(StateType::MainMenu):
	//	updateMenu();
	//	break;
	//default:
	//	break;
	//}
	//// (Tutaj problem)
	gameWindow.setFramerateLimit(10);
	gameWindow.draw(gameBackgroudSprite);
	world.render(gameWindow);
	snake.render(gameWindow);
	score = to_string(snake.getScore());
	live = to_string(snake.getLives());
	scoreBox.add("Wynik: " + score);
	scoreBox.render(gameWindow);
	liveBox.add("Liczba zyc: " + live);
	liveBox.render(gameWindow);
	gameWindow.display();
}