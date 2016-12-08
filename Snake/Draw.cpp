#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	//gameWindow.clear(Color::White);

	//// (Tutaj problem)
	gameWindow.draw(gameBackgroudSprite);
	snake.render(gameWindow);
	world.render(gameWindow);
	gameWindow.display();
}