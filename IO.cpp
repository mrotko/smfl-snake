#include "IO.hpp"


IO::IO(Game &game) {
	this->game = &game;
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "SNAKE");
	window.setFramerateLimit(60);
	loadGraphics();
	loadFont();
	time = sf::milliseconds(0);
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

sf::Vector2i IO::movement() {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return sf::Vector2i(-1, 0);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return sf::Vector2i(1, 0);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return sf::Vector2i(0, -1);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return sf::Vector2i(0, 1);
	else return sf::Vector2i(0, 0);
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

void IO::manageTime() {
	if(!game->isPause && !game->isEnd)
		time += clock.restart();
	else
		time = sf::milliseconds(HOLD_TIME - 1);
}