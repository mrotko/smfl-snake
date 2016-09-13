#include "IO.hpp"
#include "Game.hpp"

int main() {
	Game game;
	IO io(game);

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
		io.showBoard();
		io.window.display();
	}


}

// g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system