#include "Game.hpp"

Game::Game() {
	start();
}

void Game::start() {
	points = &getPlayer().getPoints();
	loadBestResults();
	isEnd = false;
	isPause = false;
	player.getBoard().setFood();
}

void Game::pause() {
	isPause = true;
}

void Game::resume() {
	isPause = false;
}

void Game::end() {
	updateBestResults();
	saveBestResults();
	isEnd = true;
}

Player & Game::getPlayer() {
	return player;
}

void Game::loadBestResults() {

}

void Game::saveBestResults() {

}

void Game::updateBestResults() {

}

int Game::getBoardValue(int x, int y) {
	return player.getBoard().getValue(x, y);
}

void Game::setFood() {
	player.getBoard().setFood();
}

void Game::move(int x, int y) {
	player.move(x, y);
}

bool Game::collision() {
	return player.getBoard().getIsCollision();
}