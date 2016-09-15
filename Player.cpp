#include "Player.hpp"
#include <iostream>

void Player::deleteTail() {
	board.clearField(tail->x, tail->y);
	Piece *x = tail;
	tail = tail->next;
	delete x;
}

Piece * Player::createPiece() {
	tmp = new Piece(headPositionX, headPositionY, nullptr);
	return tmp;
}

Player::Player() {
	headPositionX = BOARD_WIDTH/2;
	headPositionY = BOARD_HEIGHT/2;
	head = new Piece(headPositionX, headPositionY, nullptr);
	tail = new Piece(headPositionX - 1, headPositionY, head);
	board.fillField(headPositionX, headPositionY);
	board.fillField(headPositionX - 1, headPositionY);
	points = 0;
}

void Player::move(int x, int y) {
	updatePosition(x, y);
	bool food = (board.getValue(headPositionX, headPositionY) == Field::FOOD);
	if(food) {
		board.setFood();
		points++;
	}
	else 
		deleteTail();

	head->next = createPiece();
	head = head->next;
	board.fillField(headPositionX, headPositionY);

	board.getIsCollision();
}

void Player::updatePosition(int x, int y) {
	headPositionX += x;
	headPositionY += y;

	headPositionX = (headPositionX + BOARD_WIDTH) % BOARD_WIDTH;
	headPositionY = (headPositionY + BOARD_HEIGHT) % BOARD_HEIGHT;
}

Board & Player::getBoard() {
	return board;
}

int &Player::getPoints() {
	return points;
}