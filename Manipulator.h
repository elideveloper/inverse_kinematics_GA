#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include "link.h"

class Manipulator {
public:
	Manipulator(Link* links, int numLinks, Angles startingPos);
	Point computePosition();
	void reachPosition(Point dest);
	int* getJointAngles() const;
private:
	int _numLinks;
	Link* _links;
	Angles _startingPosition;									// starting angles of first link
	Link** createGeneration();
	void sortGeneration(Link** generation, Point dest);
	void takeBest(Link** generation, Point dest);
	void cross(Link* dad, Link* mom);
	void tryMutate(Link* individual, int prob);
	int computeError(Point dest);
};

#endif