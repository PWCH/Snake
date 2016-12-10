#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "World.h"
#include "Textbox.h"

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
	//Zwraca czas ktory uplynal
	Time getElapsed();
	//Resetuje zegar
	void restartClock();
	Clock clock;
	Time elapsed;
	Textbox textbox;

private:
	RenderWindow gameWindow;
	//Deklaracja sprite i tekstury tla
	Sprite gameBackgroudSprite;
	Texture gameBackgroudTexture;
	//Inicjacja gracza
	Snake snake;
	World world;
	//StateType menu;
	string score;
	string live;
};

enum class StateType {
	Intro = 1, MainMenu, Game, Paused, GameOver, Credits
};