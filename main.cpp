#include "IO.hpp"
#include "Game.hpp"

int main() {
	Game game;
	IO io(game);

	sf::Vector2i move(1, 0), tmp(1, 0), lastMove(1, 0), moveNull(0, 0);
	while(io.window.isOpen()) {
		sf::Event event;

		while(io.window.pollEvent(event)) {
			switch(event.type) {
				case sf::Event::Closed :
					io.window.close();
					break;
				case sf::Event::LostFocus:
					game.pause();
					break;
				case sf::Event::GainedFocus:
					game.resume();
					break;
				case sf::Event::KeyPressed:
					if(event.key.code == sf::Keyboard::P) {
						if(game.isPause)
							game.resume();
						else
							game.pause();
					}
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


		io.manageTime();
		if(io.time.asMilliseconds() > HOLD_TIME) {
			game.move(move.x, move.y);
			lastMove = move;
			if(game.collision())
				game.end();
			io.time = sf::milliseconds(0);
		}

		io.showBoard();
		io.showStats();
		if(game.isEnd) io.showEnd();
		else if(game.isPause) io.showPause();

		io.window.display();
	}
}

// g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system