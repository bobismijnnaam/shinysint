// Author: Bob Rubbens - Knights of the Compiler 
// Creation date: 24/11/2013 
// Contact: http://knightsofthecompiler.worpress.com - @broervanlisa - gmail (bobrubbens) 

// Includes I didn't make myself 

 // Includes I did make myself 
#include "constants.hpp"
#include "Player.hpp"

Player::Player(b2World& world, float spawnX, float spawnY) {
	// Body definition of the protagonist
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(spawnX, spawnY);
	playerBody = world.CreateBody(&bodyDef);
	
	// Define protagonist shape
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(B2D_TILE_W * 0.5, B2D_TILE_H * 0.5);
	
	// Define protagonist fixture
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	playerBody->CreateFixture(&fixtureDef);

	// Define look and smooth manes of protagonist
	playerShape.setPosition(spawnX * B2D_PPM, spawnY * B2D_PPM);
	playerShape.setSize(sf::Vector2f(B2D_TILE_W * B2D_PPM, B2D_TILE_H * B2D_PPM));
	playerShape.setOrigin(B2D_TILE_W * B2D_PPM * 0.5, B2D_TILE_H * B2D_PPM * 0.5);
	playerShape.setFillColor(sf::Color::Blue);

	xv = 0;
	yv = 0;

	playerView.setCenter(sf::Vector2f(spawnX * B2D_PPM, spawnY * B2D_PPM));
	playerView.setSize(sf::Vector2f(SCR_W, SCR_H));
}

Player::~Player() {

}

int Player::events(sf::RenderWindow& window, sf::Event e) {
	if (e.type == sf::Event::KeyPressed) {
		if (e.key.code == sf::Keyboard::Left) {
			xv = 1.5;
		} else if (e.key.code == sf::Keyboard::Right) {
			xv = 1.5;
		} else if (e.key.code == sf::Keyboard::Up) {
			yv = -1.5;
		} else if (e.key.code == sf::Keyboard::Down) {
			yv = 1.5;
		}
	} else if (e.type == sf::Event::KeyReleased) {
		if (e.key.code == sf::Keyboard::Left) {
			xv = 0;
		} else if (e.key.code == sf::Keyboard::Right) {
			xv = 0;
		} else if (e.key.code == sf::Keyboard::Up) {
			yv = 0;
		} else if (e.key.code == sf::Keyboard::Down) {
			yv = 0;
		}
	}

	return 0;
}

int Player::logic(sf::RenderWindow& window) {
	b2Vec2 impulse(xv, yv);

	playerBody->ApplyLinearImpulse(impulse, playerBody->GetPosition(), true);

	return 0;
}

int Player::draw(sf::RenderWindow& window) {
	b2Vec2 pos = playerBody->GetPosition();
	playerShape.setPosition(pos.x * B2D_PPM, pos.y * B2D_PPM);

	window.setView(playerView);

	window.draw(playerShape);

	window.setView(window.getDefaultView());

	return 0;
}

int Player::updateView() {
	b2Vec2 pos = playerBody->GetPosition();
	playerView.setCenter(pos.x * B2D_PPM, pos.y * B2D_PPM);

	return 0;
}

sf::View Player::getView() {
	return playerView;
}
