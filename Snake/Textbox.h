#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace sf;

using MessageContainer = vector<string>;

class Textbox
{
public:
	Textbox();
	//Wlasny konstruktor
	//visible - liczba wierszy
	//charSize - wielkosc czcionki
	//width - wysokosc okna tekstowego
	//screenPos - pozycja w grze
	Textbox(int visible, int charSize, int width, Vector2f screenPos);
	~Textbox();

	//Ustawianie podanych cech
	void setup(int visible, int charSize, int width, Vector2f screenPos);
	//Metoda dodawania wiadomosci
	void add(string message);
	//Czyszczenie
	void clear();
	//Wyswietlanie
	void render(RenderWindow &window);

private:
	MessageContainer messages;
	int numVisible;

	RectangleShape textBackground;
	Font font;
	Text content;
};

