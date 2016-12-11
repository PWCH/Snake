#include "Menu.h"

Menu::Menu(Vector2u wSize)
{
	if (!(font.loadFromFile("data/arial.otf")))
	{
		cout << "Nie zaladowalo czcionki menu";
	}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Graj");
	menu[0].setPosition(Vector2f(wSize.x / 2.4, wSize.y / (MAXNUM + 1) * 1.5));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Wyniki");
	menu[1].setPosition(Vector2f(wSize.x / 2.4, wSize.y / (MAXNUM + 1) * 1.8));

	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Wyjscie");
	menu[2].setPosition(Vector2f(wSize.x / 2.4, wSize.y / (MAXNUM + 1) * 2.1));

	selected = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAXNUM; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (selected - 1 >= 0)
	{
		menu[selected].setFillColor(Color::White);
		selected--;
		menu[selected].setFillColor(Color::Red);
	}
}

void Menu::moveDown()
{
	if (selected + 1 < MAXNUM)
	{
		menu[selected].setFillColor(Color::White);
		selected;
		menu[selected].setFillColor(Color::Red);
	}
}

int Menu::getPressedItem()
{
	return selected;
}