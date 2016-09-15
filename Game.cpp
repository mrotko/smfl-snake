#include "Game.hpp"
#include <iostream>

Game::Game() {
	start();
}

void Game::start() {
	player = Player();
	points = &getPlayer().getPoints();
	*points = 0;
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

bool Game::loadBestResults() {
	std::ifstream load(file);

	if(load.good()) {
		std::vector <std::string> record;
		std::string line, s1, s2, s3;

		while(getline(load, line)) {
			//	nick p date
			s1 = line.substr(0, line.find(' '));
			s2 = line.substr(s1.length()+1, line.rfind(' ') - s1.length()-1);
			s3 = line.substr(line.rfind(' ')+1);

			std::cout << s1 << " " << s2 << " " << s3 << std::endl;

			if(s1 != "" && s2 != "" && s3 != "")
				results.push_back({s1, s2, s3});
		}

	} else return false;
	return true;
}

bool Game::saveBestResults() {
	std::ofstream save(file, std::ios::trunc);

	if(save.good()) {
		for(int i = 0; i < results.size(); i++) {
			save << results[i][0] << " " << results[i][1] << " " << results[i][2] << "\n";
		}
	} else return false;
	return true;
}

bool Game::updateBestResults() {

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