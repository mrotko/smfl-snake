#include "Game.hpp"

Game::Game() {
	start();
}

void Game::start() {
	player = Player();
	points = &getPlayer().getPoints();
	*points = 0;
	isEnd = false;
	isPause = false;
}

void Game::pause() {
	isPause = true;
}

void Game::resume() {
	isPause = false;
}

void Game::end() {
	isEnd = true;
}

Player & Game::getPlayer() {
	return player;
}

bool Game::loadBestResults() {
	std::ifstream load(file);
	bool tmp = load.good();
	if(load.good()) {
		std::vector <std::string> record;
		std::string line, s1, s2, s3;
		results.clear();
		while(getline(load, line)) {
			//	nick p date
			s1 = line.substr(0, line.find(' '));
			s2 = line.substr(s1.length()+1, line.rfind(' ') - s1.length()-1);
			s3 = line.substr(line.rfind(' ')+1);

			if(s1 != "" && s2 != "" && s3 != "")
				results.push_back({s1, s2, s3});
		}

	}
	load.close();
	return tmp;
}

bool Game::saveBestResults() {
	std::ofstream save(file, std::ios::trunc);
	bool tmp = save.good();
	if(save.good()) {
		for(int i = 0; i < results.size(); i++) {
			save << results[i][0] << " " << results[i][1] << " " << results[i][2] << "\n";
		}
	}
	save.close();
	return tmp;
}

void Game::updateBestResults(std::string name, int p) {
	std::ostringstream ss;
	std::vector <std::string> record;
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);

	record.push_back(name);

	ss << p;
	record.push_back(ss.str());
	ss.str("");

	ss << std::put_time(&tm, "%d-%m-%y");
	record.push_back(ss.str());
	results.push_back(record);

	std::vector <std::vector <std::string>>::iterator it = results.begin();

	for(int i = 0; i < results.size(); i++) {
		if(atoi(record[1].c_str()) >= atoi(results[i][1].c_str())) {
			results.insert(it+i, record);
			break;
		}
	}
	
	results.pop_back();

}

int Game::getBoardValue(int x, int y) {
	return player.getBoard().getValue(x, y);
}

void Game::move(int x, int y) {
	player.move(x, y);
}

bool Game::collision() {
	return player.getBoard().getIsCollision();
}