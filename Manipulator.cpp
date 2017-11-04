#include "manipulator.h"

#include "ga_params.h"
#include "utility.h" // DELETE
Manipulator::Manipulator(Link* links, int numLinks) : _links(links), _numLinks(numLinks)
{
}

Point Manipulator::computePosition()
{
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
		this->sortGeneration(gen);
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

void Manipulator::setStartingPosition(Angles angles)
{
	this->_links[0].setAngles(angles);
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

void Manipulator::sortGeneration(Link** generation)
{

}

void Manipulator::takeBest(Link** generation, Point dest)
{
	Point pos;
	double error = 0.0;
	double minError = 9999.0;
	int bestIndIndex = 0;
	Link* currLinks = this->_links;

	for (register int i = 0; i < numIndividuals; i++) {
		this->_links = generation[i];
		pos = this->computePosition();
		error = pos.distanceTo(dest);
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
	for (register int j = 0; j < this->_numLinks; j += 2) {
		dad[j].swapJoints(mom[j]);
	}
}

void Manipulator::tryMutate(Link* individual, double prob)
{
	individual[random(this->_numLinks)].randomizeAngle();
}
