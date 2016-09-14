#include "Board.hpp"

Board::Board() {
	for(int i = 0; i < BOARD_HEIGHT; i++)
		for(int j = 0; j < BOARD_WIDTH; j++)
			board[i][j] = Field::CLEAR;

	isCollision = false;
	srand(time(0));
}

int Board::getValue(int x, int y) {
	return board[y][x];
}

void Board::fillField(int x, int y) {
	if(collision(x, y))
		isCollision = true;
	board[y][x] = Field::SNAKE;
}

void Board::clearField(int x, int y) {
	board[y][x] = Field::CLEAR;
}

bool Board::collision(int x, int y) {
	if(board[y][x] > Field::CLEAR && board[y][x] != Field::FOOD)
		return true;
	return false;
}

bool Board::getIsCollision() {
	return isCollision;
}

void Board::setFood() {
	int x, y;
	do {
		x = rand() % BOARD_WIDTH;
		y = rand() % BOARD_HEIGHT;
	} while(board[y][x] != Field::CLEAR);

	board[y][x] = Field::FOOD;
}