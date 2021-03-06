// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 17-11-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

#ifndef GAME_HPP
#define GAME_HPP

// Includes I didn't make myself
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

// Includes I did make myself
#include "ContactListener.hpp"
#include "Gamestate.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "TargetManager.hpp"

class Game : public GameState {
public:
	Game();
	~Game();
	
	int events(sf::RenderWindow& window);
	int logic(sf::RenderWindow& window);
	int render(sf::RenderWindow& window);
	
private:
	b2World world;
	b2Body* groundBody;
	b2Body* body;
	
	Map map;

	Player player;
	
	TargetManager targetManager;

	ContactListener contactListener;

	sf::Texture bgTexture;
	sf::Sprite bgShape;
} ;

#endif