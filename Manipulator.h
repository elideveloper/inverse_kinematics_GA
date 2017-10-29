#pragma once

#include "Individual.h"
#include "Point.h"

class Manipulator {
	double l1;
	double l2;
	double l3;
	double h;
	double alpha;	// initial angles
	double teta1;
	double teta2;
	double teta3;
	double computeRelativeL1Z(const Individual & ind) const;
	double computeRelativeL2Z(const Individual & ind) const;
	double computeRelativeL3Z(const Individual & ind) const;
public:
	Manipulator(double l1, double l2, double l3, double h);
	double computeX(const Individual& ind) const;
	double computeY(const Individual & ind) const;
	double computeZ(const Individual & ind) const;
	double findError(const Individual& ind, Point point) const;
	Individual getRotationAngles(const Individual& ind) const;
};
