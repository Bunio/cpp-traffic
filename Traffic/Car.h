#ifndef CAR_H
#define CAR_H

#include "GameObject2D.h"

class Car : public GameObject2D {
public:
	Car(int speed);
	void process(float delta);
	void setSpeed(int speed);
private:
	int speed;
};

#endif