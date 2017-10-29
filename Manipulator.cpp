#include "Manipulator.h"

#include <cmath>

double Manipulator::computeRelativeL1Z(const Individual & ind) const
{
	return this->l1 * sin(ind.teta1);
}

double Manipulator::computeRelativeL2Z(const Individual & ind) const
{
	return computeRelativeL1Z(ind) + this->l2 * sin(ind.teta1 + ind.teta2);
}

double Manipulator::computeRelativeL3Z(const Individual & ind) const
{
	return computeRelativeL2Z(ind) + this->l3 * sin(ind.teta1 + ind.teta2 + ind.teta3);
}

Manipulator::Manipulator(double l1, double l2, double l3, double h) : l1(l1), l2(l2), l3(l3), h(h), alpha(0.0), teta1(PI/2), teta2(-PI*3.0/4.0), teta3(-PI/4)
{
}

double Manipulator::computeX(const Individual& ind) const
{
	return cos(ind.alpha) * (this->l1 * cos(ind.teta1) + this->l2 * cos(ind.teta1 + ind.teta2) + this->l3 * cos(ind.teta1 + ind.teta2 + ind.teta3));
}

double Manipulator::computeY(const Individual& ind) const
{
	return sin(ind.alpha) * (this->l1 * cos(ind.teta1) + this->l2 * cos(ind.teta1 + ind.teta2) + this->l3 * cos(ind.teta1 + ind.teta2 + ind.teta3));
}

double Manipulator::computeZ(const Individual& ind) const
{
	return this->h + this->computeRelativeL3Z(ind);
}

double Manipulator::findError(const Individual& ind, Point point) const
{
	double z = this->computeZ(ind);
	if (z < 0.0 || h + this->computeRelativeL2Z(ind) < 0.0 || h + this->computeRelativeL1Z(ind) < 0.0) {
		return this->l1 + this->l2 + this->l3;													// return big error
	}
	return point.distanceTo(this->computeX(ind), this->computeY(ind), this->computeZ(ind));
}

Individual Manipulator::getRotationAngles(const Individual& ind) const
{
	Individual rotInd;
	rotInd.alpha = ind.alpha - this->alpha;
	rotInd.teta1 = ind.teta1 - this->teta1;
	rotInd.teta2 = ind.teta2 - this->teta2;
	rotInd.teta3 = ind.teta3 - this->teta3;
	return rotInd;
}
