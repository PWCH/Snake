#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Menu.h"

int main()
{
	RenderWindow menuWindow(VideoMode(800, 600), "Snake");
	Texture gameBackgroudTexture;
	Sprite gameBackgroudSprite;
	gameBackgroudTexture.loadFromFile("data/menu.png");
	gameBackgroudSprite.setTexture(gameBackgroudTexture);
	Vector2u size(menuWindow.getSize().x, menuWindow.getSize().y);

	Menu menu(size);
	

	while (menuWindow.isOpen())
	{
		Event event;

		while (menuWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.moveUp();
					//cout << "Gora";
					break;

				case Keyboard::Down:
					menu.moveDown();
					//cout << "Dol";
					break;

				case Keyboard::Return:
					Engine engine;
					switch (menu.getPressedItem())
					{
					case 0:
						engine.start(menuWindow);
						//cout << "Tutaj";
						menuWindow.clear();
						break;
					case 1:
						cout << "Wyniki jeszcze nie dodane";
						break;
					case 2:
						menuWindow.close();
						break;
					}
					break;
				}
				break;
			case Event::Closed:
				menuWindow.close();
				break;
			}
		}
		menuWindow.clear();
		menuWindow.draw(gameBackgroudSprite);
		menu.draw(menuWindow);
		menuWindow.display();
	}
}
