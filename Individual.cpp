#include "Individual.h"

#include <iostream>

Individual::Individual()
{
	this->teta1 = (rand() % ((int)(2 * PI * 1000) + 1) - PI * 1000) / 1000.0;
	this->teta2 = (rand() % ((int)(2 * PI * 1000) + 1) - PI * 1000) / 1000.0;
	this->teta3 = (rand() % ((int)(2 * PI * 1000) + 1) - PI * 1000) / 1000.0;
}

Individual::Individual(const Individual& ind)
{
	this->teta1 = ind.teta1;
	this->teta2 = ind.teta2;
	this->teta3 = ind.teta3;
}

Individual& Individual::operator=(const Individual& ind)
{
	this->teta1 = ind.teta1;
	this->teta2 = ind.teta2;
	this->teta3 = ind.teta3;
	return *this;
}

void Individual::mutate()
{
	this->teta1 += (rand() % ((int)(abs(this->teta1) * 0.2 * 1000) + 1) - this->teta1 * 0.1 * 1000) / 1000.0;
	this->teta2 += (rand() % ((int)(abs(this->teta2) * 0.2 * 1000) + 1) - this->teta2 * 0.1 * 1000) / 1000.0;
	this->teta3 += (rand() % ((int)(abs(this->teta3) * 0.2 * 1000) + 1) - this->teta3 * 0.1 * 1000) / 1000.0;
}
