#include "Snake.h"

//Konstruktor ustawiajacy wielkosc Shape weza
Snake::Snake(int blockSize)
{
	size = blockSize;
	snakeRect.setSize(Vector2f(size - 1, size - 1));
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