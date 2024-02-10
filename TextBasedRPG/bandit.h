#pragma once
#include "health.h"

class Bandit : public health {

public:
	static const uint16_t SPAWN_HP = 8u;

	Bandit() : health(SPAWN_HP) {}

private:

};