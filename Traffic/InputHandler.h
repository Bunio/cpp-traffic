#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#pragma once
#include "Player.h"

class InputHandler {
public:
	InputHandler(Player * player);
	void handleInput(float delta);
private:
	Player * player;
};

#endif