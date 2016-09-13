#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include "Player.hpp"
#include <string>
#include <fstream>

#define HOLD_TIME 400

class Game {
	Player player;
	std::string playerName;
	std::string file = "bestResults.txt";
	bool gameIsActive;
	int points;
public:
	Game();
	void start();
	void pause();
	void resume();
	void end();
	void setPlayerName(std::string name);
	std::string getPlayerName();
	Player & getPlayer();
	void loadBestResults();
	void saveBestResults();
	void updateBestResults();
	int getBoardValue(int x, int y);
	void setFood();
	void move(int x, int y);
};


#endif // SNAKE_GAME_HPP