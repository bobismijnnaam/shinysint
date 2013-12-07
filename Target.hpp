// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 4/12/2013
// Contact: http://knightsofthecompiler.worpress.com - @broervanlisa - gmail (bobrubbens)

#ifndef TARGET_HPP
#define TARGET_HPP

// Includes I didn't make myself
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

// Includes I did make myself

class Target {
public:
	Target(b2World& world, sf::Texture& targetTexture, int offX, int offY);
	~Target();

	int logic(sf::RenderWindow& window);
	int draw(sf::RenderWindow& window);

	int playerColl();
	int playerExitColl();

	bool isDead();

private:
	// sf::RectangleShape targetShape;
	sf::Sprite targetShape;
	b2Body* targetBody;
	bool dead;
} ;

#endif