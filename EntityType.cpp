// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 4/12/2013
// Contact: http://knightsofthecompiler.worpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself

// Includes I did make myself
#include "constants.hpp"
#include "EntityType.hpp"
#include "Target.hpp"

// Entity base type
EntityType::EntityType(int inputType, void* inputPayload) {
	type = inputType;
	payload = inputPayload;

}

EntityType::~EntityType() {
	
}

int EntityType::getType() {
	return type;
}

void* EntityType::getPayload() {
	return payload;
}

// Target Type
/*
TargetType::TargetType(Target& inputTarget) : target(inputTarget) {
	
}

TargetType::~TargetType() {

}

int TargetType::getType() {
	return TYPE_TARGET;
}

Target& TargetType::getTarget() {
	return target;
} */