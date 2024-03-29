#include "IO.hpp"

IO::IO(Game &game) {
	this->game = &game;
	WINDOW_HEIGHT = BOARD_HEIGHT * BLOCK_HEIGHT;
	WINDOW_WIDTH = BOARD_WIDTH * BLOCK_WIDTH + 150;
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

void IO::showEnd() {
	std::string s1 = "GAME IS OVER!", s2 = "New game [N]", s3 = "Save result [S]", s4 = "Ranking [R]", s5 = "Exit [E]";
	sf::Text message(s1 + "\n\n" + s2 + "\n\n" + s3 + "\n\n" + s4 + "\n\n" + s5, font, 30);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		game->start();
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		std::string name = getName();
		if(name == "") name = "#";
		game->updateBestResults(name, *(game->points));
		game->saveBestResults();
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		showRanking();
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		window.close();
	window.draw(message);
}

void IO::showPause() {
	sf::Text message("PAUSE", font, 30);
	message.setPosition(BOARD_WIDTH*BLOCK_WIDTH/2-2*BLOCK_WIDTH, BOARD_HEIGHT*BLOCK_HEIGHT/2);
	window.draw(message);
}

void IO::showStats() {
	std::ostringstream ss;

	ss << *(game->points);

	sf::Text stats("Points\n" + ss.str(), font);

	stats.setPosition(BOARD_WIDTH*BLOCK_WIDTH + BLOCK_WIDTH, BOARD_HEIGHT*BLOCK_HEIGHT/3);
	window.draw(stats);
}

void IO::showRanking() {
	sf::RenderWindow window(sf::VideoMode(400, 400, 32), "Ranking");
	window.setFramerateLimit(30);

	std::ostringstream ss;
	sf::Text rank("", font, 15);

	int tmp = game->getResults().size(), l = 1;

	while(tmp /= 10) l++;

	std::left(ss);

	for(int i = 0; i < game->getResults().size() && i < 20; i++) {
		ss << std::setw(l) << i+1 << " "
		<< std::setw(20) << game->getResults()[i][0] 
		<< std::setw(5) << game->getResults()[i][1] 
		<< std::setw(12) << game->getResults()[i][2] << "\n";
	}

	while(window.isOpen()) {
		sf::Event event;

		while(window.pollEvent(event)) {
			switch(event.type) {
				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		rank.setString(ss.str());
		window.clear();
		window.draw(rank);
		window.display();
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

void IO::manageTime() {
	if(!game->isPause && !game->isEnd)
		time += clock.restart();
	else
		time = sf::milliseconds(HOLD_TIME - 1);
}

std::string IO::getName() {
	std::string name, display = "Save as: ";
	sf::Text message(display, font, 20);
	sf::RenderWindow window(sf::VideoMode(300, 200, 32), "Save");
	window.setFramerateLimit(30);
	while(window.isOpen()) {
		sf::Event event;
		window.clear();
		while(window.pollEvent(event)) {
			switch(event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::TextEntered:
					if(event.text.unicode == 13) window.close();
					if(event.text.unicode == 32) break;
					if(event.text.unicode == 8)
                        name = name.substr(0, name.length() - 1);
                    else if(event.text.unicode > 32)
                    	name += (char) event.text.unicode;
					break;
			}
		}
		message.setString(display + name);	
		window.draw(message);
		window.display();
	}
	return name;
}