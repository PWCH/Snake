#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"

using namespace sf;

class Engine
{
public:
	Engine();
	~Engine();
	//Start wywola wszystkie prywatne funkcje
	void start();
private:
	RenderWindow gameWindow;
	//Deklaracja sprite i tekstury tla
	Sprite gameBackgroudSprite;
	Texture gameBackgroudTexture;

	//Inicjacja gracza
	//Prywatne funckje tylko do uzytku wewnetrznego
	//void input();
	//void update(float dtAsSeconds);
	void draw();
};