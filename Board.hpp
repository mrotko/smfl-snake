#ifndef SNAKE_BOARD_HPP
#define SNAKE_BOARD_HPP

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20

class Board {
	int board[BOARD_HEIGHT][BOARD_WIDTH];
	bool isCollision;

public:
	Board();
	int getValue(int x, int y);
	void setValue(int x, int y, int value);
	void clearField(int x, int y);
	bool collision(int x, int y);
};


#endif // SNAKE_BOARD_HPP