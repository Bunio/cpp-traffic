#pragma once

class GameObject {
public:
	GameObject();
	virtual void process(float delta) = 0;
private:
};