#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	//gameWindow.clear(Color::White);

	//// (Tutaj problem)
	gameWindow.setFramerateLimit(10);
	gameWindow.draw(gameBackgroudSprite);
	world.render(gameWindow);
	snake.render(gameWindow);
	textbox.render(gameWindow);
	gameWindow.display();
}