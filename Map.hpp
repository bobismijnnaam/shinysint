// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 19-11-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

#ifndef MAP_HPP
#define MAP_HPP

// Includes I didn't make myself
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <vector>

// Includes I did make myself
#include "Tile.hpp"


class Map {
public:
	Map(b2World& world, std::vector<std::string>& lvl);
	~Map();
	
	int events(sf::RenderWindow& window, sf::Event e);
	int logic(sf::RenderWindow& window);
	int draw(sf::RenderWindow& window, sf::View view);
	
private:
	std::vector<Tile> tiles;
} ;

#endif