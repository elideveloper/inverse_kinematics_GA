#pragma once

#include "utility.h"

struct Individual {
	double teta1;
	double teta2;
	double teta3;
	Individual();
	Individual(const Individual& ind);
	Individual& operator=(const Individual& ind);
	void mutate();
};