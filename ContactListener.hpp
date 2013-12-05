// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 4/12/2013
// Contact: http://knightsofthecompiler.worpress.com - @broervanlisa - gmail (bobrubbens)

#ifndef CONTACTLISTENER_HPP
#define CONTACTLISTENER_HPP

// Includes I didn't make myself
#include <Box2D/Box2D.h>

// Includes I did make myself

class ContactListener : public b2ContactListener {
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
} ;

#endif