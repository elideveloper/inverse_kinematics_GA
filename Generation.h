#pragma once

#include "Manipulator.h"
#include "Individual.h"

class Generation {
	int numInds;
	Individual** inds;
public:
	Generation(int numInds);
	void sort(const Manipulator& manip, const Point& destPoint);
	void turnToNext(const Manipulator& manip, const Point& destPoint, int numLeaveBest, int numCrossover, double mutateProb);
	void cross(int momNo, int dadNo);
	void tryMutate(int indNo, double prob);
	Individual* getBestInd() const;
};