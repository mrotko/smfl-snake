#include "Board.hpp"

Board::Board() {

	for(int i = 0; i < BOARD_HEIGHT; i++)
		for(int j = 0; j < BOARD_WIDTH; j++)
			board[i][j] = 0;

	isCollision = false;
}

int Board::getValue(int x, int y) {
	return board[y][x];
}

void Board::setValue(int x, int y, int value) {
	if(collision(x, y))
		isCollision = true;
	board[y][x] = value;
}

void Board::clearField(int x, int y) {
	board[y][x] = 0;
}

bool Board::collision(int x, int y) {
	if(board[y][x] > 0)
		return true;
	return false;
}