#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#pragma once
#include "Player.h"
#include "GameObject.h"

class InputHandler : public GameObject2D{
public:
	InputHandler(Player * player);
	void process(float delta);
private:
	Player * player;
};

#endif