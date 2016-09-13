#include "IO.hpp"


IO::IO(Game &game) {
	this->game = &game;
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "SNAKE");
	window.setFramerateLimit(60);
	loadGraphics();
	loadFont();
}


void IO::showBoard() {
	int value;

	for(int i = 0; i < BOARD_HEIGHT; i++) {
		for(int j = 0; j < BOARD_WIDTH; j++) {
			value = game->getBoardValue(j, i);
			shape[value].setPosition(j*BLOCK_WIDTH, i*BLOCK_HEIGHT);
			window.draw(shape[value]);			
		}
	}
}

bool IO::loadGraphics() {

	if(texture.loadFromFile("blocks.png") != true)
		return false;

	for(int i = 0; i < SHAPES; i++) {
		shape[i].setSize(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
		shape[i].setTexture(&texture);
		shape[i].setTextureRect(sf::IntRect(BLOCK_WIDTH * i, 0, BLOCK_WIDTH, BLOCK_HEIGHT));
	}
	return true;
}

bool IO::loadFont() {
	
	return font.loadFromFile("consola.ttf");
}