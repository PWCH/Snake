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
	//Jesli snakeBody nie jest puste to zwroc pozycje pierwszego segmentu lub pozycje 1 1
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