// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 5-12-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself
#include <Box2D/Box2d.h>
#include <iostream>
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "constants.hpp"
#include "globals.hpp"
#include "Menu.hpp"


Menu::Menu() {
	// get bitches fuck money

	captionTexture.loadFromFile("Media/caption.png");
	captionShape.setTexture(captionTexture);
}

Menu::~Menu() {
	
}

int Menu::events(sf::RenderWindow& window) {
	sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            gm->setNextState(STATE_EXIT);
        }
	}
	
	return 0;
}

int Menu::logic(sf::RenderWindow& window) {
	
	return 0;
}

int Menu::render(sf::RenderWindow& window) {

	window.clear(sf::Color(120, 120, 120, 255));

	window.draw(captionShape);
	
	window.display();

	return 0;
}
