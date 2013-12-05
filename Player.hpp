// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 24/11/2013
// Contact: http://knightsofthecompiler.worpress.com - @broervanlisa - gmail (bobrubbens)

#ifndef PLAYER_HPP
#define PLAYER_HPP

// Includes I didn't make myself
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

 // Includes I did make myself


class Player {
public:
	Player(b2World& world, float spawnX, float spawnY);
	~Player();

	int events(sf::RenderWindow& window, sf::Event e);
	int logic(sf::RenderWindow& window);
	int draw(sf::RenderWindow& window);

	int updateView();
	sf::View getView();

private:
	b2Body* playerBody;
	sf::Sprite playerShape;
	sf::Texture playerTexture;
	// sf::CircleShape playerShape;
	sf::View playerView;

	float xv, yv;
};

#endif
