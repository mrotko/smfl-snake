#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include <string>

#define HOLD_TIME 400

class Game {
	Player player;
	std::string playerName;
public:
	Game();
	void start();
	void pause();
	void resume();
	void end();
};


#endif // SNAKE_GAME_HPP