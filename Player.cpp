#include "Player.hpp"

void Player::deleteTail() {
	board.clearField(tail->x, tail->y);
	Piece *x = tail;
	tail = tail->next;
	delete x;
}

Piece * Player::createPiece(int x, int y) {
	tmp = new Piece(x, y, nullptr);
	return tmp;
}

Player::Player() {
	head = new Piece(BOARD_WIDTH/2, BOARD_HEIGHT/2, nullptr);
	tail = new Piece(BOARD_WIDTH/2, BOARD_HEIGHT/2, head);
}

Player::Player(int x, int y) {
	tmp = new Piece(x, y, nullptr);
	head = tmp;
	tail = tmp;
}

void Player::move(int x, int y) {
	head->next = createPiece(x, y);
	head = head->next;
	board.fillField(x, y);
	deleteTail();
}

void Player::add(int x, int y) {
	head->next = createPiece(x, y);
	head = head->next;
	board.fillField(x, y);
}

Board & Player::getBoard() {
	return board;
}
