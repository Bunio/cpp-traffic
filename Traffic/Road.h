#ifndef ROAD_H
#define ROAD_H
#include "GameObject2D.h"

class Road : public GameObject2D {
public:
	Road();
	void process(float delta);
	void setSpeed(int speed);
private:
	int speed;
};

#endif