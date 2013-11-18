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

Game::Game() : world(b2Vec2(0.0f, -10.0f)) {
	// Body definition of ground
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
	
	// Create actual ground body object in world
	groundBody = world.CreateBody(&groundBodyDef);
	
	// Add shape to the ground object (to make collision possible)
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);
	
	// Body definition of the protagonist
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	
	// Create actual protagonist body object in world
	body = world.CreateBody(&bodyDef);
	
	// Define protagonist shape
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	
	// Define protagonist fixture
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);
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
	world.Step(SCR_SPF, B2D_ITERATIONS_VELOCITY, B2D_ITERATIONS_POSITION);
	b2Vec2 position = body->GetPosition();
	float angle = body->GetAngle();
	std::cout << "Angle: " << angle << " Xpos: " << position.x << " Ypos: " << position.y << "\n";
	
	return 0;
}

int Game::render(sf::RenderWindow& window) {

	return 0;
}
