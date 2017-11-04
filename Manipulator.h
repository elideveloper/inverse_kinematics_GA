#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include "link.h"

class Manipulator {
public:
	Manipulator(Link* links, int numLinks, Angles startingPos);
	Point computePosition();
	void reachPosition(Point dest);
	double* getJointAngles() const;
private:
	int _numLinks;
	Link* _links;
	Link** createGeneration();
	Angles _startingPosition;									// starting angles of first link
	void sortGeneration(Link** generation, Point dest);
	void takeBest(Link** generation, Point dest);
	void cross(Link* dad, Link* mom);
	void tryMutate(Link* individual, double prob);
	double computeError(Point dest);
};

#endif