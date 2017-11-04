#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include "link.h"

class Manipulator {
public:
	Manipulator(Link* links, int numLinks);
	Point computePosition();
	void reachPosition(Point dest);
	void setStartingPosition(Angles angles);
private:
	int _numLinks;
	Link* _links;
	Link** createGeneration();
	void sortGeneration(Link** generation);
	void takeBest(Link** generation, Point dest);
	void cross(Link* dad, Link* mom);
	void tryMutate(Link* individual, double prob);
};

#endif