#include "World.h"



World::World(Vector2u wSize)
{
	size = 20;
	//Przypisanie rozmiarow okna
	windowSize = wSize;
	respawnFood();
	if (!(foodTexture.loadFromFile("data/food.png")))
	{
		cout << "Nie zaladowano tekstury jedzenia";
	}
	if (!(music.openFromFile("data/musiceat.ogg")))
	{
		cout << "Nie zaladowana dzwieku jedzenia";
	}
	foodShape.setTexture(&foodTexture);
	foodShape.setOrigin(Vector2f(size / 2, size / 2));
	foodShape.setSize(Vector2f(size - 1, size - 1));

	//Pêtla ustawiaj¹ca krawêdzie
	for (int i = 0; i < 4; ++i)
	{
		bounds[i].setFillColor(Color(150, 0, 0));
		if (!((i + 1) % 2) && (i != 1))
			bounds[i].setSize(Vector2f(windowSize.x, size - 9));
		else
			bounds[i].setSize(Vector2f(size - 9, windowSize.y));
		if (i < 2)
		{
			if (i < 1)
				bounds[i].setSize(Vector2f(windowSize.x, size + 10));
			bounds[i].setPosition(0, 0);
		}
		else
		{
			bounds[i].setOrigin(bounds[i].getSize());
			bounds[i].setPosition(Vector2f(windowSize));
		}
	}
}


World::~World()
{
}

void World::respawnFood()
{
	//Maksymalne pole gdzie moze znalezc sie jedzenie
	int maxX = (windowSize.x / size) - 3;
	int maxY = (windowSize.y / size) - 3;
	//Losowe umieszczanie jedzenia 
	item = Vector2i(rand() % maxX + 3, rand() % maxY + 3);
	foodShape.setPosition(item.x * size, item.y * size);
}

void World::update(Snake &player)
{
	//Zwiekszanie weza gdy pozycja weza jest rowna pozycji jedzenia
	if (player.getPosition() == item)
	{
		music.play();
		player.increase();
		player.increaseScore();
		player.increaseSpeed();
		respawnFood();
	}

	//Wielkosc siatki
	int gridSizeX = windowSize.x / size;
	int gridSizeY = windowSize.y / size;

	//Warunki do straty zycia
	if (player.getPosition().x <= 0 || player.getPosition().y <= 1 || player.getPosition().x >= gridSizeX || player.getPosition().y >= gridSizeY)
	{
		player.lose();
	}
}

void World::render(RenderWindow &window)
{
	for (int i = 0; i < 4; ++i)
	{
		window.draw(bounds[i]);
	}
	window.draw(foodShape);
}

int World::getBlockSize()
{
	return size;
}