// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 19-11-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "constants.hpp"
#include "Tile.hpp"

Tile::Tile(int x, int y, b2World& world) : tileImage(sf::Vector2f(B2D_PPM * B2D_TILE_W, B2D_PPM * B2D_TILE_H)) {
	b2BodyDef tileBodyDef;
	tileBodyDef.position.Set((-0.5 + x) * B2D_TILE_W, (-0.5 + y) * B2D_TILE_H);
	
	tileBody = world.CreateBody(&tileBodyDef);
	
	b2PolygonShape tileBox;
	tileBox.SetAsBox(B2D_TILE_W * 0.5, B2D_TILE_H * 0.5);
	tileBody->CreateFixture(&tileBox, 0.0f);
	
	sf::Vector2f s = tileImage.getSize();
	tileImage.setOrigin(s.x * 0.5, s.y * 0.5);
	tileImage.setPosition( (-0.5 + x) * B2D_TILE_W * B2D_PPM , (-0.5 + y) * B2D_TILE_H * B2D_PPM);
}

Tile::~Tile() {
	// Most of the variables will go out of scope
	// The deletion of the world variable will lead delete the tileBody variable
}

int Tile::draw(sf::RenderWindow& window) {
	window.draw(tileImage);
	
	return 0;
}
