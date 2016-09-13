#include "Game.hpp"

Game::Game() {
	playerName = "";
	
	start();
}

void Game::start() {
	points = 0;
	loadBestResults();
	gameIsActive = true;
}

void Game::pause() {
	gameIsActive = false;
}

void Game::resume() {
	gameIsActive = true;
}

void Game::end() {
	updateBestResults();
	saveBestResults();
	gameIsActive = false;
}

void Game::setPlayerName(std::string name) {
	playerName = name;
}
	
std::string Game::getPlayerName() {
	return playerName;
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