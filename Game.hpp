#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include "Player.hpp"
#include <string>
#include <fstream>
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
	bool updateBestResults();
	int getBoardValue(int x, int y);
	void setFood();
	void move(int x, int y);
	bool collision();
};


#endif // SNAKE_GAME_HPP