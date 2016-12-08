#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	//gameWindow.clear(Color::White);

	//// (Tutaj problem)
	world.render(gameWindow);
	snake.render(gameWindow);
	gameWindow.draw(gameBackgroudSprite);
	gameWindow.display();
}