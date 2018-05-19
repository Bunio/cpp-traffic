#pragma once
#include "Player.h"

class InputHandler {
public:
	InputHandler(Player* player);
	void handleInput(float delta);
private:
	Player* player;
};