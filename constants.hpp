// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 17-11-13
// Contact: http://knightsofthecompiler.wordpress.com - @broervanlisa - gmail (bobrubbens)

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

// Includes I didn't make myself
#include <string>

// Includes I did make myself

const int SCR_W = 640;
const int SCR_H = 480;
const int SCR_FPS = 60;
const float SCR_SPF = 1 / (float)SCR_FPS;
const std::string SCR_TITLE = "Where did my suprise go?";

const int B2D_ITERATIONS_POSITION = 3;
const int B2D_ITERATIONS_VELOCITY = 8;

#endif