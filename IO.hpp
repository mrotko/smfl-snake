#ifndef SNAKE_IO_HPP
#define SNAKE_IO_HPP

#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>

#define BLOCK_WIDTH 20
#define BLOCK_HEIGHT 20
#define SHAPES 4


class IO {
	Game *game;	
	sf::Texture texture;
	sf::Font font;
	sf::RectangleShape shape[SHAPES];	// 0-empty, 1-snake, 2-food, 3-rock
	int WINDOW_WIDTH, WINDOW_HEIGHT;
public:
	sf::RenderWindow window;
	sf::Time time;
	sf::Clock clock;
	IO(Game &game);
	sf::Vector2i movement();
	void showBoard();
	void showEnd();
	void showPause();
	void showStats();
	void showRanking();
	bool loadGraphics();
	bool loadFont();
	void manageTime();
	std::string getName();
};

#endif // SNAKE_IO_HPP
