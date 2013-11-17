// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 17-11-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "Game.hpp"
#include "globals.hpp"

Game::Game() {

}

Game::~Game() {

}

int Game::events(sf::RenderWindow& window) {
	sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            gm->setNextState(STATE_EXIT);
        }
	}
	
	return 0;
}

int Game::logic(sf::RenderWindow& window) {

	return 0;
}

int Game::render(sf::RenderWindow& window) {

	return 0;
}
