#include "IO.hpp"
#include "Game.hpp"


int main() {
	Game game;
	IO io(game);
	sf::Vector2i move(1, 0);
	while(io.window.isOpen()) {
		sf::Event event;

		while(io.window.pollEvent(event)) {
			switch(event.type) {
				case sf::Event::Closed :
					io.window.close();
					break;
				default:
					break;
			}
		}


		io.window.clear();
		sf::Vector2i last = move;
		move = io.movement();
		if(move == sf::Vector2i(0, 0) || move + last == sf::Vector2i(0, 0))
			move = last;

		game.move(move.x, move.y);
		io.showBoard();
		io.window.display();
	}


}

// g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system