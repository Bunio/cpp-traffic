#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include "GameObject2D.h"

class Button : public GameObject2D {
public:
	void process(float delta);
};

#endif