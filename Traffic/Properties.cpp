#include "Properties.h"
#include <iostream>

Properties::Properties() {};
int Properties::SCENE_WIDTH = 700;
int Properties::SCENE_HEIGHT = 1024;
int Properties::LINE_1_X = 120;
int Properties::LINE_2_X = 340;
int Properties::LINE_3_X = 540;
int Properties::BASE_SPEED = 500;

int Properties::CAR_SPEED = 200;
int Properties::CAR_INITIAL_Y = 0;
int Properties::CAR_MANAGER_DELAY_MIN = 4;
int Properties::CAR_MANAGER_DELAY_MAX = 4;
int Properties::CAR_MANAGER_AMOUNT_MIN = 3;
int Properties::CAR_MANAGER_AMOUNT_MAX = 5;

int Properties::COIN_SPEED = 300;
int Properties::COIN_INITIAL_Y = 0;
int Properties::COIN_MANAGER_DELAY_MIN = 1;
int Properties::COIN_MANAGER_DELAY_MAX = 10;
int Properties::COIN_MANAGER_AMOUNT_MIN = 3;
int Properties::COIN_MANAGER_AMOUNT_MAX = 12;

float Properties::SPEED_MODIFIER = 1.5;
float Properties::SPEED_MODIFIER_MIN = 1.5;
float Properties::SPEED_MODIFIER_MAX = 4.0;
float Properties::SPEED_MODIFIER_INCREASE = 1.03;
float Properties::SPEED_MODIFIER_DECREASE = 0.99;