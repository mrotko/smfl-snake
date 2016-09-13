#ifndef SNAKE_BOARD_HPP
#define SNAKE_BOARD_HPP

#include <cstdlib>
#include <ctime>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20

enum Field {CLEAR, SNAKE, FOOD, ROCK};

class Board {
	int board[BOARD_HEIGHT][BOARD_WIDTH];
	bool isCollision;
public:
	Board();
	int getValue(int x, int y);
	void fillField(int x, int y);
	void clearField(int x, int y);
	bool collision(int x, int y);
	bool getIsCollision();
	void setFood();
};


#endif // SNAKE_BOARD_HPP