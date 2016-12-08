#include "Snake.h"

//Konstruktor ustawiajacy wielkosc Shape weza
Snake::Snake(int blockSize)
{
	size = 16;
	//snakeRect.setSize(Vector2f(size - 1, size - 1));
};
Snake::~Snake()
{
}

void Snake::reset()
{
	//Wyczyszczenie weza
	snakeBody.clear();

	//Dodawanie do vectora 3 segmenty - standardowa wielkosc weza
	snakeBody.push_back(SnakeSegment(5, 7));
	snakeBody.push_back(SnakeSegment(5, 6));
	snakeBody.push_back(SnakeSegment(5, 5));

	//Ustawienie kierunku na none, gracz wybiera strone
	setDirection(Direction::None);

	//Parametry startowe weza
	snakeSpeed = 15;
	snakeLives = 3;
	snakeLost = false;
}

void Snake::setDirection(Direction direction)
{
	dir = direction;
}

Direction Snake::getDirection()
{
	return dir;

}
int Snake::getSpeed()
{
	return snakeSpeed;
}
int Snake::getLives()
{
	return snakeLives;
}
int Snake::getScore()
{
	return snakeScore;
}

Vector2i Snake::getPosition()
{
	//Jesli snakeBody nie jest puste to zwroc pozycje pierwszego segmentu w innym przypadku pozycje 1 1
	return (!snakeBody.empty() ? snakeBody.front().position : Vector2i(1, 1));
}

//Deklaracja metod zmieniajacy podstawowe paramentry
void Snake::increaseScore()
{
	snakeScore += 10;
}
bool Snake::hasLost()
{
	return snakeLost;
}
void Snake::lose()
{
	snakeLost = true;
}
void Snake::toggleLost()
{
	snakeLost = !snakeLost;
}

//Funkcja zwiekszajaca weza
void Snake::increase()
{
	if (snakeBody.empty())
		return;
	//Wskaznik do ogona weza (ostatniego segmentu)
	SnakeSegment &tail_head = snakeBody[snakeBody.size() - 1];

	if (snakeBody.size() > 1)
	{
		//Wskaznik do przeostatniego segmentu
		SnakeSegment &tail_bone = snakeBody[snakeBody.size() - 2];
		//Ostatnie dwa segmenty weza sa w pionie  
		if (tail_head.position.x == tail_bone.position.x)
		{
			//Ostatni jest nizej niz przedostatni (waz idzie w gore)
			if (tail_head.position.y > tail_bone.position.y)
			{
				//Dodanie segmentu w pozycji x, y+1
				snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_bone.position.y + 1));
			}
			else
			{
				snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_bone.position.y - 1));
			}
		}
		//Ostatnie dwa segmenty sa w poziomie
		else if (tail_head.position.y == tail_bone.position.y)
		{
			//Ostatni jest bardziej po prawej niz przedostatni (waz idzie w lewo)
			if (tail_head.position.x > tail_bone.position.x)
			{
				snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_bone.position.y));
			}
			else
			{
				snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_bone.position.y));
			}
		}
	}
	else
	{
		//Zwiekszanie weza gdy klikniety dany przycisk
		if (dir == Direction::Up)
		{
			snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
		}
		else if(dir == Direction::Down)
		{
			snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
		}
		else if(dir == Direction::Right)
		{
			snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
		}
		else if (dir == Direction::Left)
		{
			snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
		}
	}
}

void Snake::update()
{
	//Pomijamy ruch i kolizje gdy snake jest pusty lub nie wykryto startowego klawisza
	if (snakeBody.empty())
		return;
	if (dir == Direction::None)
		return;
	move();
	sCollision();
}

void Snake::move()
{
	//Przesuwamy weza od tylu
	for (int i = snakeBody.size() - 1; i > 0; i--)
	{
		snakeBody[i].position = snakeBody[i - 1].position;
	}
	//Przesuwamy glowe weza 
	if (dir == Direction::Left)
		--snakeBody[0].position.x;
	else if (dir == Direction::Right)
		++snakeBody[0].position.x;
	else if (dir == Direction::Up)
		--snakeBody[0].position.y;
	else if (dir == Direction::Down)
		++snakeBody[0].position.y;
}

void Snake::cut(int numberOfSegments)
{
	//Usuwanie z vectora podana liczbe segmentow ze strata zycia
	for (int i = 0; i < numberOfSegments; i++)
	{
		snakeBody.pop_back();
	}
	--snakeLives;
	if (!snakeLives)
	{
		lose();
		return;
	}
}

void Snake::sCollision()
{
	//Sprawdzanie kolizji gdy waz wiekszy od 4
	if (snakeBody.size() < 5)
		return;
	//Wskaznik do glowy weza
	SnakeSegment &head = snakeBody.front();
	//Iteracja, itr wskazuje na pierwszy element vectora i idzie az do konca vectora
	for (auto itr = snakeBody.begin() + 1; itr != snakeBody.end(); ++itr)
	{
		//Jesli pozycja glowy == pozycji segmentu w ktorym jest teraz iterator nastepuje odciecie ogona
		if (itr->position == head.position)
		{
			int segments = snakeBody.end() - itr;
			//Metoda odcinania ogona 
			cut(segments);
			break;
		}
	}
}

void Snake::render(RenderWindow &gameWindow)
{
	if (snakeBody.empty())
		return;
	//Ustawianie i rysowanie glowy weza
	auto head = snakeBody.begin();
	if (!(snakeHeadTex.loadFromFile("data/snake.png")))
	{
		cout << "Nie zaladowano tekstury glowy weza";
	}
	snakeRect.setTexture(snakeHeadTex);
	snakeRect.setPosition(head->position.x * size, head->position.y * size);
	gameWindow.draw(snakeRect);
	//Ustawianie i rysowanie ciala
	if (!(snakeTex.loadFromFile("data/snakeb.png")))
	{
		cout << "Nie zaladowano tekstury weza";
	}
	snakeRect.setTexture(snakeTex);
	for (auto itr = snakeBody.begin() + 1; itr != snakeBody.end(); ++itr)
	{
		snakeRect.setPosition(itr->position.x * size, itr->position.y * size);
		gameWindow.draw(snakeRect);
	}
}