// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 19-11-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <vector>

// Includes I did make myself
#include "constants.hpp"
#include "Map.hpp"
#include "Tile.hpp"

Map::Map(b2World& world) {
	tiles.reserve(100);
	
	for (int i = 0; i < 100; ++i) {
		tiles.push_back(Tile(rand() % 100, rand() % 100, world));
	}
	
	view.setCenter(sf::Vector2f(1000, 1000));
	view.setSize(sf::Vector2f(SCR_W, SCR_H));
}

Map::~Map() {

}

int Map::draw(sf::RenderWindow& window) {
	window.setView(view);
	
	for (Tile& t : tiles) {
		t.draw(window);
	}
	
	window.setView(window.getDefaultView());
	
	return 0;
}
