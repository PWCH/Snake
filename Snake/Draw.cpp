#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	//Czysci ostatnia klatke
	gameWindow.clear(Color::White);
	
	//Rysuje tlo
	gameWindow.draw(gameBackgroudSprite);

	gameWindow.display();

}