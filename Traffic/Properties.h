#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <iostream>

class Properties {
public:
	Properties();
	static int SCENE_WIDTH;
	static int SCENE_HEIGHT;
	static int LINE_1_X;
	static int LINE_2_X;
	static int LINE_3_X;
	static int BASE_SPEED;

	static int CAR_SPEED;
	static int CAR_INITIAL_Y;
	static int CAR_MANAGER_DELAY_MIN;
	static int CAR_MANAGER_DELAY_MAX;
	static int CAR_MANAGER_AMOUNT_MIN;
	static int CAR_MANAGER_AMOUNT_MAX;

	static int COIN_SPEED;
	static int COIN_INITIAL_Y;
	static int COIN_MANAGER_DELAY_MIN;
	static int COIN_MANAGER_DELAY_MAX;
	static int COIN_MANAGER_AMOUNT_MIN;
	static int COIN_MANAGER_AMOUNT_MAX;

	static float SPEED_MODIFIER;
};

#endif