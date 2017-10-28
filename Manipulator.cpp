#include "Manipulator.h"

#include <cmath>

Manipulator::Manipulator(double l1, double l2, double l3) : l1(l1), l2(l2), l3(l3)
{
}

double Manipulator::computeX(const Individual& ind) const
{
	return this->l1 * cos(ind.teta1) + this->l2 * cos(ind.teta1 + ind.teta2) + this->l3 * cos(ind.teta1 + ind.teta2 + ind.teta3);
}

double Manipulator::computeY(const Individual& ind) const
{
	return this->l1 * sin(ind.teta1) + this->l2 * sin(ind.teta1 + ind.teta2) + this->l3 * sin(ind.teta1 + ind.teta2 + ind.teta3);
}

double Manipulator::findError(const Individual& ind, Point point) const
{
	return point.distanceTo(this->computeX(ind), this->computeY(ind));
}
