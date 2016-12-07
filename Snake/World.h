#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"

using namespace sf;

class World
{
public:
	World(Vector2u wSize);
	~World();

	int getBlockSize();

	//Umieszczanie jedzenia
	void respawnFood();

	//Aktualizacja gracza
	void update(Snake &player);
	void render(RenderWindow &gameWindow);

private:
	//Wielkosc okna
	Vector2u windowSize;
	Vector2i item;
	//Wielkosc grafiki jedzenia
	int size;
	//Shape jedzenia
	RectangleShape foodShape;
	Texture foodTexture;
	//Shape krawedzi
	RectangleShape bounds[4];
};