#include "Engine.h"

void Engine::input()
{
	if (Keyboard::isKeyPressed(Keyboard::Up) && (snake.getDirection() != Direction::Down))
		snake.setDirection(Direction::Up);
	if (Keyboard::isKeyPressed(Keyboard::Down) && (snake.getDirection() != Direction::Up))
		snake.setDirection(Direction::Down);
	if (Keyboard::isKeyPressed(Keyboard::Left) && (snake.getDirection() != Direction::Right))
		snake.setDirection(Direction::Left);
	if (Keyboard::isKeyPressed(Keyboard::Right) && (snake.getDirection() != Direction::Left))
		snake.setDirection(Direction::Right);
	//if (Keyboard::isKeyPressed(Keyboard::P))
	//{
	//	pause = !pause;
	//	gameoverBox.render(gameWindow);
	//}
}