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

Manipulator::Manipulator(double l1, double l2, double l3, double h, double alpha, double teta1, double teta2, double teta3) 
	: l1(l1), l2(l2), l3(l3), h(h), alpha(alpha), teta1(teta1), teta2(teta2), teta3(teta3)
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

Individual Manipulator::getServoAngles(const Individual& ind) const
{
	Individual rotInd;
	rotInd.alpha = this->alpha + ind.alpha;
	rotInd.teta1 = this->teta1 + ind.teta1;
	rotInd.teta2 = this->teta2 + ind.teta2;
	rotInd.teta3 = this->teta3 + ind.teta3;
	return rotInd;
}
