#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Menu.h"

int main()
{
	RenderWindow gameWindow(VideoMode(800, 600), "Snake");

	Vector2u size(gameWindow.getSize().x, gameWindow.getSize().y);

	Menu menu(size);

	while (gameWindow.isOpen())
	{
		Event event;
		Engine engine;

		while (gameWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.moveUp();
					cout << "Gora";
					menu.getPressedItem();
					break;

				case Keyboard::Down:
					menu.moveDown();
					cout << "Dol";
					menu.getPressedItem();
					break;

				case Keyboard::Return:
					{
					case 0:
						engine.start();
						break;
					case 1:
						cout << "Option button has been pressed";
						break;
					case 2:
						gameWindow.close();
						break;
					}

					break;
				}

				break;
			case Event::Closed:
				gameWindow.close();
				break;
			}
		}

		gameWindow.clear();
		menu.draw(gameWindow);
		gameWindow.display();
	}
}
