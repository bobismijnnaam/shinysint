// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 5-12-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

#ifndef MENU_HPP
#define MENU_HPP

// Includes I didn't make myself
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

// Includes I did make myself
#include "Gamestate.hpp"

class Menu : public GameState {
public:
	Menu();
	~Menu();
	
	int events(sf::RenderWindow& window);
	int logic(sf::RenderWindow& window);
	int render(sf::RenderWindow& window);
	
private:
	sf::Texture captionTexture;
	sf::Sprite captionShape;
} ;

#endif