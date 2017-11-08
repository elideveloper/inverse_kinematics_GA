#include "manipulator.h"

#include "ga_params.h"
#include "utility.h"

Manipulator::Manipulator(Link* links, int numLinks, Angles startingPos) : _links(links), _numLinks(numLinks), _startingPosition(startingPos)
{
}

Point Manipulator::computePosition()
{
	this->_links[0].setAngles(this->_startingPosition);			// set starting position for first link
	Point p = this->_links[0].computeB();
	for (register int i = 1; i < this->_numLinks; i++) {
		this->_links[i].setA(p);
		this->_links[i].setAngles(this->_links[i - 1].getAngles());
		p = this->_links[i].computeB(this->_links[i - 1]);
	}
	return p;
}

void Manipulator::reachPosition(Point dest)
{
	Link** gen = this->createGeneration();
	for (register int n = 0; n < maxIterations; n++) {
		this->sortGeneration(gen, dest);
		for (register int i = 0; i < numCrossover; i += 2) {
			this->cross(gen[numLeaveBest + i], gen[numLeaveBest + i + 1]);
		}
		for (register int i = numLeaveBest; i < numLeaveBest + numCrossover; i++) {
			this->tryMutate(gen[i], mutateProb);
		}
		for (register int i = numLeaveBest + numCrossover; i < numIndividuals; i++) {
			for (register int j = 0; j < this->_numLinks; j++) {
				gen[i][j] = Link(this->_links[j]);
				gen[i][j].randomizeAngle();
			}
		}
	}

	this->takeBest(gen, dest);

	// release memory
	for (register int i = 0; i < numIndividuals; i++) {
		delete[] gen[i];
	}
	delete[] gen;
}

int * Manipulator::getJointAngles() const
{
	int* angles = new int[this->_numLinks];
	for (int i = 0; i < this->_numLinks; i++) angles[i] = this->_links[i].getTurn();
	return angles;
}

Link** Manipulator::createGeneration()
{
	Link** generation = new Link*[numIndividuals];
	for (register int i = 0; i < numIndividuals; i++) {
		generation[i] = new Link[this->_numLinks];
		for (register int j = 0; j < this->_numLinks; j++) {
			generation[i][j] = Link(this->_links[j]);
			if (i != 0) generation[i][j].randomizeAngle();
		}
	}
	return generation;
}

void Manipulator::sortGeneration(Link** generation, Point dest)
{
	int maxError = 0;
	for (register int i = 0; i < this->_numLinks; i++) {
		maxError += this->_links[i].getLength();
	}
	maxError *= 2;
	Link* currLinks = this->_links;
	Link** errorsArr = new Link*[maxError]();
	Point pos;
	int error = 0;
	for (register int i = 0; i < numIndividuals; i++) {
		this->_links = generation[i];
		error = computeError(dest);
		while (errorsArr[error] != nullptr) error++;
		errorsArr[error] = generation[i];
	}

	int j = 0;
	for (register int i = 0; i < maxError; i++) {
		if (errorsArr[i] != nullptr) {
			generation[j] = errorsArr[i];
			if (j == numIndividuals - 1) break;
			j++;
		}
	}
	this->_links = currLinks;
	delete[] errorsArr;
}

void Manipulator::takeBest(Link** generation, Point dest)
{
	Point pos;
	int error = 0;
	int minError = 9999;
	int bestIndIndex = 0;
	Link* currLinks = this->_links;

	for (register int i = 0; i < numIndividuals; i++) {
		this->_links = generation[i];
		error = computeError(dest);
		if (error < minError) {
			minError = error;
			bestIndIndex = i;
		}
	}

	// take the best individual
	this->_links = currLinks;
	for (register int j = 0; j < this->_numLinks; j++) {
		this->_links[j] = generation[bestIndIndex][j];
	}
}

void Manipulator::cross(Link* dad, Link* mom)
{
	for (register int j = 1; j < this->_numLinks; j += 2) {
		dad[j].swapJoints(mom[j]);
	}
}

void Manipulator::tryMutate(Link* individual, int prob)
{
	int mutNo = random(this->_numLinks * 100 / prob);
	if (mutNo < this->_numLinks) individual[mutNo].randomizeAngle();
}

// reimplement, introduce obstacles
int Manipulator::computeError(Point dest)
{
	Point pos = this->computePosition();
	for (register int i = 0; i < this->_numLinks; i++) {
		if (this->_links[i].isIntersectsHorizPlane(0)) {
			int maxError = 0;
			for (register int j = 0; j < this->_numLinks; j++) {
				maxError += this->_links[j].getLength();
			}
			return maxError;
		}
	}
	return pos.distanceTo(dest);
}
