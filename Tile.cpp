// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 19-11-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself
#include <Box2D/Box2D.h>
#include <iostream>
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "constants.hpp"
#include "functions.hpp"
#include "Tile.hpp"

// ID counter 
int Tile::idCounter = 0;

Tile::Tile(int x, int y, b2Body* container, sf::Texture& tileSheet, TileType tileType) : tileShape(tileSheet) { // tileShape(sf::Vector2f(B2D_PPM * B2D_TILE_W, B2D_PPM * B2D_TILE_H)) {
	// Image definition
	tileShape.setOrigin(B2D_TILE_W * B2D_PPM * 0.5, B2D_TILE_H * B2D_PPM * 0.5);
	tileShape.setPosition( (0.5 + x) * B2D_TILE_W * B2D_PPM , (0.5 + y) * B2D_TILE_H * B2D_PPM);

	switch (tileType) {
		case TileType::Wall:
			{	
				b2PolygonShape tileBox;
				tileBox.SetAsBox(B2D_TILE_W * 0.5, B2D_TILE_H * 0.5, b2Vec2((0.5 + x) * B2D_TILE_W, (0.5 + y) * B2D_TILE_H), 0);
				container->CreateFixture(&tileBox, 0.0f);

				// tileShape.setFillColor(sf::Color::Red);
				tileShape.setTextureRect(sf::IntRect(0, 0, 32, 32));

				break;
			}
		case TileType::Floor:
			// tileShape.setFillColor(sf::Color::Green);

			tileShape.setTextureRect(sf::IntRect(32, 0, 32, 32));

			break;
		case TileType::Outside:
			// tileShape.setFillColor(sf::Color(120, 120, 120, 255));

			tileShape.setTextureRect(sf::IntRect(64, 0, 32, 32));

			break;
	}

	id = idCounter++;
	type = tileType;
}

Tile::~Tile() {
	// Most of the variables will go out of scope
	// The deletion of the world variable will lead delete the tileBody variable
}

int Tile::logic(sf::RenderWindow& window) {
	// b2Vec2 position = tileBody->GetPosition();
	// tileShape.setPosition(sf::Vector2f(position.x * B2D_PPM, position.y * B2D_PPM));

	// if (id == 10) std::cout << "ID: " << id << " Position (X | Y): " << position.x << " | " << position.y << "\n";

	return 0;
}

int Tile::draw(sf::RenderWindow& window) {
	window.draw(tileShape);
	
	return 0;
}
