#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include "Player.hpp"
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

#define HOLD_TIME 100

class Game {
	Player player;
	std::string file = "bestResults.txt";
	std::vector <std::vector <std::string>> results;
public:
	bool isPause;
	bool isEnd;
	int *points;

	Game();
	void start();
	void pause();
	void resume();
	void end();
	Player & getPlayer();
	bool loadBestResults();
	bool saveBestResults();
	void updateBestResults(std::string name, int p);
	int getBoardValue(int x, int y);
	void move(int x, int y);
	bool collision();
	void setName(std::string name);
};


#endif // SNAKE_GAME_HPP