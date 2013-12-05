// Author: Bob Rubbens - Knights of the Compiler
// Creation date: 4/12/2013
// Contact: http://knightsofthecompiler.worpress.com - @broervanlisa - gmail (bobrubbens)

// Includes I didn't make myself

// Includes I did make myself
#include "Target.hpp"

class EntityType {
public:
	EntityType(int inputType, void* inputPayload);
	~EntityType();

	int getType();
	void* getPayload();

private:
	int type;
	void* payload;
} ;

/*
class TargetType : public EntityType {
public:
	TargetType(Target& inputTarget);
	~TargetType();

	int getType();
	Target& getTarget();

private:
	Target& target;
} ;
*/