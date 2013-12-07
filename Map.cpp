// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 19-11-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself
#include <Box2D/Box2D.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

// Includes I did make myself
#include "constants.hpp"
#include "Map.hpp"
#include "Tile.hpp"

Map::Map(b2World& world, std::vector<std::string>& lvl) {
	tileSheet.loadFromFile("Media/tilesheet.png", sf::IntRect());

	// Prepare level generation
	tiles.reserve(lvl.size() * lvl.size());

	// Physics definition
	b2BodyDef tileBodyDef;
	tileBodyDef.position.Set(0, 0);
	
	wallContainer = world.CreateBody(&tileBodyDef);

	for (int y = 0; y < lvl.size(); ++y) {
		for (int x = 0; x < lvl.at(y).length(); ++x) {
			if (lvl.at(y)[x] == '#') {
				tiles.push_back(Tile(x, y, wallContainer, tileSheet, TileType::Wall));
			} else if (lvl.at(y)[x] == '.' || lvl.at(y)[x] == '@') {
				tiles.push_back(Tile(x, y, wallContainer, tileSheet, TileType::Floor));
			} else if (lvl.at(y)[x] == '*') {
				tiles.push_back(Tile(x, y, wallContainer, tileSheet, TileType::Outside));
			}
		}
	}
}

Map::~Map() {

}

int Map::events(sf::RenderWindow& window, sf::Event e) { 

	return 0;
}

int Map::logic(sf::RenderWindow& window) {
	for (Tile& t : tiles) {
		t.logic(window);
	}

	return 0;
}

int Map::draw(sf::RenderWindow& window, sf::View view) {
	window.setView(view);
	
	for (Tile& t : tiles) {
		t.draw(window);
	}
	
	window.setView(window.getDefaultView());
	
	return 0;
}
