#pragma once
#include "health.h"

class Dwarf : public health {

public:
	static const uint16_t SPAWN_HP = 8u;

	Dwarf() : health(SPAWN_HP) {}

private:

};