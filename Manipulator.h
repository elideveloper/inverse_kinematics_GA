#pragma once

#include "Individual.h"
#include "Point.h"

class Manipulator {
	double l1;
	double l2;
	double l3;
public:
	Manipulator(double l1, double l2, double l3);
	double computeX(const Individual& ind) const;
	double computeY(const Individual & ind) const;
	double computeZ(const Individual & ind) const;
	double findError(const Individual& ind, Point point) const;
};
