#include "Player.hpp"

void Player::deleteTail() {
	board.clearField(tail->x, tail->y);
	tail = tail->next;
}

Piece * Player::createPiece(int x, int y) {
	tmp = new Piece(x, y, head);
	return tmp;
}

Player::Player() {
	tmp = new Piece(BOARD_WIDTH/2, BOARD_HEIGHT/2, nullptr);
	head = tmp;
	tail = tmp;
}

Player::Player(int x, int y) {
	tmp = new Piece(x, y, nullptr);
	head = tmp;
	tail = tmp;
}

void Player::move(int x, int y) {
	head = createPiece(x, y);
	board.fillField(x, y);
	deleteTail();
}

void Player::add(int x, int y) {
	head = createPiece(x, y);
	board.fillField(x, y);
}