// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 4/12/2013
// Contact: http://knightsofthecompiler.worpress.com - @broervanlisa - gmail (bobrubbens)

#ifndef TARGETMANAGER_HPP
#define TARGETMANAGER_HPP

// Includes I didn't make myself
#include <vector>

// Includes I did make myself
#include "Target.hpp"

class TargetManager {
public:
	TargetManager(b2World& world, int amount);
	~TargetManager();

	int logic(sf::RenderWindow& window);
	int draw(sf::RenderWindow& window, Player& player);

	int clean(b2World& world);

	bool isAllDead();
	
private:
	std::vector<Target*> targets;

	sf::Texture targetTexture;
} ;

#endif