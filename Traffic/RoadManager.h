#include "GameObject.h"
#include "Road.h"
#include <list>

class RoadManager : public GameObject {
public:
	RoadManager();
	void process(float delta);
	std::vector<Road*> getRoads();

private:
	Road road1, road2;
	void buildRoads();
	int speed;
	int roadHeight;
};
