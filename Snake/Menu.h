#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#define MAXNUM 3

using namespace sf;
using namespace std;

class Menu
{
public:
	Menu(Vector2u wSize);
	~Menu();

	void draw(RenderWindow &gameWindow);
	void moveUp();
	void moveDown();
	int getPressedItem();

private:
	int selected;
	Font font;
	Text menu[MAXNUM];
};

