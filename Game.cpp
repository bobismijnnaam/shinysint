// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 17-11-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself
#include <Box2D/Box2d.h>
#include <iostream>
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "constants.hpp"
#include "ContactListener.hpp"
#include "Game.hpp"
#include "globals.hpp"
#include "levels.hpp"
#include "Target.hpp"

Game::Game() : 	world(b2Vec2(0.0f, 0.0f)),
				map(world, level1),
				player(world, 3, 3),
				targetManager(world, 10) {
	// wut
	// WATCH ME
	world.SetContactListener(&contactListener);

	bgTexture.loadFromFile("Media/bg.png");
	bgShape.setTexture(bgTexture);
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

	targetManager.clean(world);

	if (targetManager.isAllDead()) {
		gm->setNextState(STATE_MENU);
	}
	
	return 0;
}

int Game::render(sf::RenderWindow& window) {

	window.clear(sf::Color(120, 120, 120, 255));

	window.draw(bgShape);
	
	map.draw(window, player.getView());

	player.draw(window);

	targetManager.draw(window, player);
	
	window.display();

	return 0;
}
