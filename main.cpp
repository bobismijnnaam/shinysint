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
    sf::RenderWindow window(sf::VideoMode(SCR_W, SCR_H), "Where did my suprise go?");

    gm = new GameMan(STATE_GAME);

    while (gm->getState() != STATE_EXIT) {
        gm->currState->events(window);

        gm->currState->logic(window);

        gm->changeState();

        gm->currState->render(window);
    }

    std::cout << "Bye!";

    delete gm;

    return 0;
}