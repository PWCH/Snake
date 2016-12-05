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
	//setDirection(Direction::None);

	//Parametry startowe weza
	snakeSpeed = 15;
	snakeLives = 3;
	snakeLost = false;
}

