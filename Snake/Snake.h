#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

//Struktura weza
struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	Vector2i position;
};
//Skrocona wersja vector <SnakeSegment>
using SnakeContainer = vector <SnakeSegment>;

//Kierunek
enum class Direction { None, Up, Down, Left, Right };

class Snake
{
public:
	Snake(int blockSize);
	~Snake();

	//Przydatne metody
	//Ustawianie kierunku
	void setDirection(Direction dir);
	//Pobieranie kierunku
	Direction getDirection();
	//Pobieranie pozycji
	Vector2i getPosition();
	//Pobieranie ilosci zyc
	int getLives();
	//Pobieranie wyniku
	int getScore();
	//Pobieranie predkosci 
	int getSpeed();
	//Zwiekszanie wyniku
	void increaseScore();
	//Strata zycia
	bool hasLost();

	//Przegranie
	void lose();
	//Przelacznik przegrania
	void toggleLost();

	//Zwiekszanie weza
	void increase();
	//Reset weza
	void reset();

	//Metoda ruchu
	void move();
	//Metoda aktualizacji
	void update();
	//Metoda skracaja weza
	void cut(int numberOfSegments);

private:
	//Sprawdznie kolizji
	void sCollision();
	//Vektor segmentow weza
	SnakeContainer snakeBody;
	//Wielkosc grafiki weza
	int size;
	//Kierunek biezacy
	Direction dir;
	//Predkosc, liczba zyc, wynik, stracone
	int snakeSpeed;
	int snakeLives;
	int snakeScore;
	int snakeLost;
	//Shape weza
	RectangleShape snakeRect;
	
};