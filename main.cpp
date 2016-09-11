#include <SFML/Graphics.hpp>

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

sf::RenderWindow App;

int main() {
	App.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP), "GAME");

	while(App.isOpen()) {
		App.clear();
		App.display();
	}

}