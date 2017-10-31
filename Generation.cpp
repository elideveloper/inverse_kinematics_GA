#include "Generation.h"

#include <queue>

Generation::Generation(int numInds) : numInds(numInds)
{
	this->inds = new Individual*[numInds];
	for (int i = 0; i < numInds; i++) {
		this->inds[i] = new Individual(PIdiv2, PIdiv2, PIdiv2, PIdiv2);
	}
}

void Generation::sort(const Manipulator& manip, const Point& destPoint)
{
	double* errorsArr = new double[this->numInds];
	std::priority_queue<double> errors;
	for (int i = 0; i < this->numInds; i++) {
		errorsArr[i] = manip.findError(*(this->inds[i]), destPoint);
		errors.push(errorsArr[i]);
	}
	Individual* ind = nullptr;
	double err = 0.0;
	for (int i = this->numInds - 1; i >= 0; i--) {
		for (int j = 0; j <  this->numInds; j++) {
			if (abs(errors.top() - errorsArr[j]) < std::numeric_limits<double>::min()) {
				ind = this->inds[j];
				this->inds[j] = this->inds[i];
				this->inds[i] = ind;
				err = errorsArr[j];
				errorsArr[j] = errorsArr[i];
				errorsArr[i] = err;
				break;
			}
		}
		errors.pop();
	}
	delete[] errorsArr;
}

void Generation::turnToNext(const Manipulator& manip, const Point& destPoint, int numLeaveBest, int numCrossover, double mutateProb)
{
	this->sort(manip, destPoint);
	for (int i = 0, j = 1; i <= numCrossover; i += 2, j = i += 2) {
		this->cross(numLeaveBest + i, numLeaveBest + j);
	}
	for (int i = numLeaveBest; i < numLeaveBest + numCrossover; i++) {
		this->tryMutate(i, mutateProb);
	}
	for (int i = numLeaveBest + numCrossover; i < this->numInds; i++) {
		delete this->inds[i];
		this->inds[i] = new Individual(PIdiv2, PIdiv2, PIdiv2, PIdiv2);
	}
}

void Generation::cross(int momNo, int dadNo)
{
	double mT1 = this->inds[momNo]->teta1;
	this->inds[momNo]->teta1 = this->inds[dadNo]->teta1;
	this->inds[dadNo]->teta1 = mT1;
}

void Generation::tryMutate(int indNo, double prob)
{
	if (((rand() % 101) / 100.0) < prob) this->inds[indNo]->mutate();
}

Individual* Generation::getBestInd() const
{
	return this->inds[0];
}
