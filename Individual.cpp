#include "Individual.h"

#include <iostream>

Individual::Individual()
{
	this->teta1 = (rand() % ((int)(PI * 1000) + 1) - PIdiv2 * 1000) / 1000.0;
	this->teta2 = (rand() % ((int)(PI * 1000) + 1) - PIdiv2 * 1000) / 1000.0;
	this->teta3 = (rand() % ((int)(PI * 1000) + 1) - PIdiv2 * 1000) / 1000.0;
	this->alpha = (rand() % ((int)(PI * 1000) + 1) - PIdiv2 * 1000) / 1000.0;
}

Individual::Individual(double maxAlphaDev, double maxTeta1Dev, double maxTeta2Dev, double maxTeta3Dev)
{
	this->teta1 = (rand() % ((int)(maxTeta1Dev * 2 * 1000) + 1) - maxTeta1Dev * 1000) / 1000.0;
	this->teta2 = (rand() % ((int)(maxTeta2Dev * 2 * 1000) + 1) - maxTeta2Dev * 1000) / 1000.0;
	this->teta3 = (rand() % ((int)(maxTeta3Dev * 2 * 1000) + 1) - maxTeta3Dev * 1000) / 1000.0;
	this->alpha = (rand() % ((int)(maxAlphaDev * 2 * 1000) + 1) - maxAlphaDev * 1000) / 1000.0;
}

Individual::Individual(const Individual& ind)
{
	this->teta1 = ind.teta1;
	this->teta2 = ind.teta2;
	this->teta3 = ind.teta3;
	this->alpha = ind.alpha;
}

Individual& Individual::operator=(const Individual& ind)
{
	this->teta1 = ind.teta1;
	this->teta2 = ind.teta2;
	this->teta3 = ind.teta3;
	this->alpha = ind.alpha;
	return *this;
}

void Individual::mutate()
{/*
	this->teta1 += (rand() % ((int)(abs(this->teta1) * 0.2 * 1000) + 1) - this->teta1 * 0.1 * 1000) / 1000.0;
	this->teta2 += (rand() % ((int)(abs(this->teta2) * 0.2 * 1000) + 1) - this->teta2 * 0.1 * 1000) / 1000.0;
	this->teta3 += (rand() % ((int)(abs(this->teta3) * 0.2 * 1000) + 1) - this->teta3 * 0.1 * 1000) / 1000.0;
	this->alpha += (rand() % ((int)(abs(this->alpha) * 0.2 * 1000) + 1) - this->alpha * 0.1 * 1000) / 1000.0;
*/}
