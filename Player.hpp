#ifndef SNAKE_PLAYER_HPP
#define SNAKE_PLAYER_HPP

// #include "Board.hpp"

struct Piece {
	int x, y;
	Piece *next;
	Piece(int x, int y, Piece *ptr) {
		this->x = x;
		this->y = y;
		this->next = ptr;
	}
};

class Player {
	// Board board;
	Piece *head, *tail, *tmp;

	void deleteTail();
	Piece * createPiece(int x, int y);
public:
	Player();
	Player(int x, int y);
	void move(int x, int y);	
	void add(int x, int y);
};



#endif // SNAKE_PLAYER_HPP