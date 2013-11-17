// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 17-11-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself
#include <iostream>
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "constants.hpp"
#include "Gamestate.hpp"
#include "globals.hpp"

int main() {
	std::cout << "hi";	
	
    sf::RenderWindow window(sf::VideoMode(SCR_W, SCR_H), "Where did my suprise go?");

    gm = new GameMan(STATE_GAME);
	
	sf::Clock timelord;
	sf::Time minion;
	float timekeeper = 0;

    while (gm->getState() != STATE_EXIT) {
		minion = timelord.restart();
		timekeeper += minion.asSeconds();
	
		while (timekeeper >= SCR_SPF) {
			gm->currState->events(window);
			
			gm->currState->logic(window);
			
			timekeeper -= SCR_SPF;
		}

        gm->changeState();

        gm->currState->render(window);
    }

    std::cout << "Bye!";

    delete gm;

    return 0;
}