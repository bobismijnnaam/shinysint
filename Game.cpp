// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 17-11-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself
#include <Box2D/Box2d.h>
#include <iostream>
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "constants.hpp"
#include "Game.hpp"
#include "globals.hpp"
#include "levels.hpp"

Game::Game() : 	world(b2Vec2(0.0f, 0.0f)),
				map(world, level1),
				player(world, 3, 3) {
	// wut
}

Game::~Game() {
	
}

int Game::events(sf::RenderWindow& window) {
	sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            gm->setNextState(STATE_EXIT);
        }

        map.events(window, event);

        player.events(window, event);
	}
	
	return 0;
}

int Game::logic(sf::RenderWindow& window) {

	map.logic(window);

	player.logic(window);
	
	world.Step(SCR_SPF, B2D_ITERATIONS_VELOCITY, B2D_ITERATIONS_POSITION);

	player.updateView();
	
	return 0;
}

int Game::render(sf::RenderWindow& window) {

	window.clear(sf::Color(120, 120, 120, 255));
	
	map.draw(window, player.getView());

	player.draw(window);
	
	window.display();

	return 0;
}
