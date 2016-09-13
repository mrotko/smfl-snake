#include "IO.hpp"
#include "Game.hpp"
#include <iostream>
using namespace std;



int main() {
	Game game;
	IO io(game);

	sf::Time time;
	sf::Clock clock;
	sf::Vector2i move(1, 0), tmp(1, 0), lastMove(1, 0), moveNull(0, 0);
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
		
		tmp = move;
		move = io.movement();
		if(move == moveNull || move + tmp == moveNull || move + lastMove == moveNull)
			move = tmp;


		time = clock.getElapsedTime();
		if(time.asMilliseconds() > HOLD_TIME) {
			game.move(move.x, move.y);
			lastMove = move;
			clock.restart();
		}

		io.showBoard();
		io.window.display();
	}


}

// g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system