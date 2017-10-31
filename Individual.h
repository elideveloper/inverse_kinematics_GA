#pragma once

#include "utility.h"

struct Individual {
	double teta1;
	double teta2;
	double teta3;
	double alpha;
	Individual();
	Individual(double maxAlphaDev, double maxTeta1Dev, double maxTeta2Dev, double maxTeta3Dev);		// max symmetrical deviations of angles
	Individual(const Individual& ind);
	Individual& operator=(const Individual& ind);
	void mutate();
};
