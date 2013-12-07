// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 4/12/2013
// Contact: http://knightsofthecompiler.worpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself
#include <Box2D/Box2D.h>
#include <iostream>

// Includes I did make myself
#include "constants.hpp"
#include "EntityType.hpp"
#include "levels.hpp"
#include "Target.hpp"

Target::Target(b2World& world, sf::Texture& targetTexture, int offX, int offY) {
	/* int offX = rand() % 15, offY = rand() % 15;

	while (level1.at(offY)[offX] != MAP_FLOOR) {
		offX = rand() % 15;
		offY = rand() % 15;
	} */

	float xPos = (offX + 0.5) * B2D_TILE_W;
	float yPos = (offY + 0.5) * B2D_TILE_H;

	targetShape.setPosition(xPos * B2D_PPM, yPos * B2D_PPM);
	// targetShape.setSize(sf::Vector2f(B2D_TILE_W * B2D_PPM, B2D_TILE_H * B2D_PPM));
	targetShape.setOrigin(B2D_TILE_W * B2D_PPM * 0.5, B2D_TILE_H * B2D_PPM * 0.5);
	// targetShape.setFillColor(sf::Color(150, 150, 150, 255));
	targetShape.setTexture(targetTexture);
	
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(xPos, yPos);
	bodyDef.userData = new EntityType(TYPE_TARGET, this);
	targetBody = world.CreateBody(&bodyDef);

	b2PolygonShape targetShape;
	targetShape.SetAsBox(B2D_TILE_W * 0.5, B2D_TILE_H * 0.5);

	b2FixtureDef targetFixture;
	targetFixture.shape = &targetShape;
	targetFixture.density = 1;
	targetFixture.isSensor = true;
	targetBody->CreateFixture(&targetFixture);

	dead = false;
}

Target::~Target() {
	targetBody->GetWorld()->DestroyBody(targetBody);
}

int Target::logic(sf::RenderWindow& window) {
	// Nothing to see here... Yet.
	return 0;
}

int Target::draw(sf::RenderWindow& window) {
	window.draw(targetShape);

	return 0;
}

int Target::playerColl() {
	// targetShape.setFillColor(sf::Color(255, 0, 255, 255));

	dead = true;

	return 0;
}

int Target::playerExitColl() {
	// targetShape.setFillColor(sf::Color(150, 150, 150, 255));

	return 0;
}

bool Target::isDead() {
	return dead;
}
