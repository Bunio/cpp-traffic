#ifndef ROAD_H
#define ROAD_H
#include "GameObject.h"

class Road : public GameObject {
public:
	Road();
	void process(float delta);
	void setSpeed(int speed);
private:
	int speed;
};

#endif