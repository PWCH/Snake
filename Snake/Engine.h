#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "World.h"

using namespace sf;

class Engine
{
public:
	Engine();
	~Engine();
	
	//Obsluga klawiatury
	void input();
	void update();
	void start();
	void draw();
	//Rzut okna
	Window *getWindow();
	Vector2u Wi
	//Zwraca czas ktory uplynal
	Time getElapsed();
	//Resetuje zegar
	void restartClock();
	Clock clock;
	Time elapsed;

private:
	RenderWindow gameWindow;
	//Deklaracja sprite i tekstury tla
	Sprite gameBackgroudSprite;
	Texture gameBackgroudTexture;

	//Inicjacja gracza
	Snake snake;
	World world;

};