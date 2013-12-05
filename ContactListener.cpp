// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 4/12/2013
// Contact: http://knightsofthecompiler.worpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself
#include <Box2D/Box2D.h>
#include <iostream>

// Includes I did make myself
#include "constants.hpp"
#include "ContactListener.hpp"
#include "EntityType.hpp"

void ContactListener::BeginContact(b2Contact* contact) {
	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	EntityType* possibleType;
	Target* target;

	if (bodyUserData) {
		possibleType = static_cast<EntityType*>(bodyUserData);
		switch (possibleType->getType()) {
			case TYPE_TARGET:
					target = static_cast<Target*>(possibleType->getPayload());
					target->playerColl();
					return;

					break;
			default:
				break;
		}
	}

	bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData) {
		possibleType = static_cast<EntityType*>(bodyUserData);
		switch (possibleType->getType()) {
			case TYPE_TARGET:
					target = static_cast<Target*>(possibleType->getPayload());
					target->playerColl();
					return;

					break;
			default:
				break;
		}
	}
}

void ContactListener::EndContact(b2Contact* contact) {
	/*
	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	EntityType* possibleType;
	Target* target;

	if (bodyUserData) {
		possibleType = static_cast<EntityType*>(bodyUserData);
		switch (possibleType->getType()) {
			case TYPE_TARGET:
					target = static_cast<Target*>(possibleType->getPayload());
					target->playerExitColl();
					return;

					break;
			default:
				break;
		}
	}

	bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData) {
		possibleType = static_cast<EntityType*>(bodyUserData);
		switch (possibleType->getType()) {
			case TYPE_TARGET:
					target = static_cast<Target*>(possibleType->getPayload());
					target->playerExitColl();
					return;

					break;
			default:
				break;
		}
	}
	*/
}
