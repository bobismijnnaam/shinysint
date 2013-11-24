// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 19-11-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

#ifndef TILE_HPP
#define TILE_HPP

// Includes I didn't make myself
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

// Includes I did make myself


class Tile {
public:
	Tile(int x, int y, b2World& world);
	~Tile();
	
	int logic(sf::RenderWindow& window);
	int draw(sf::RenderWindow& window);
	
private:
	b2Body* tileBody;
	// sf::Sprite tileImage;
	sf::RectangleShape tileShape;
	
	static int idCounter;
	int id;

} ;

#endif