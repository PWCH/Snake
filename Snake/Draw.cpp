#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	//Czyœci ostatni¹ klatkê
	gameWindow.clear(Color::White);

	//Rysuje t³o
	gameWindow.draw(gameBackgroudSprite);

	gameWindow.display();

}