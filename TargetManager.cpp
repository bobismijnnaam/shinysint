// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 4/12/2013
// Contact: http://knightsofthecompiler.worpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself
#include <iostream>

// Includes I did make myself
#include "levels.hpp"
#include "Player.hpp"
#include "Target.hpp"
#include "TargetManager.hpp"

TargetManager::TargetManager(b2World& world, int amount) {
	targetTexture.loadFromFile("Media/enemy.png");

	/*
	for (int i = 0; i < amount; ++i) {
		targets.push_back(new Target(world, targetTexture));
	}
	*/

	for (int y = 0; y < level1.size(); ++y) {
		for (int x = 0; x < level1.at(y).length(); ++x) {
			if (level1.at(y)[x] == '@') {
				targets.push_back(new Target(world, targetTexture, x, y));
			} 
		}
	}
}

TargetManager::~TargetManager() {
	// Should go out of scope and thus destroyed
}

int TargetManager::logic(sf::RenderWindow& window) {
	for (Target* target : targets) {
		target->logic(window);
	}

	return 0;
}

int TargetManager::draw(sf::RenderWindow& window, Player& player) {
	window.setView(player.getView());

	for (Target* target : targets) {
		target->draw(window);
	}

	window.setView(window.getDefaultView());

	return 0;
}

int TargetManager::clean(b2World& world) {
	for (int i = 0; i < targets.size(); ++i) {
		if (targets.at(i)->isDead()) {
			delete targets.at(i);
			targets.erase(targets.begin()+i);
		}
	}

	return 0;
}

bool TargetManager::isAllDead() {
	return targets.size() == 0;
}
