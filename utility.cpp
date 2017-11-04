#include "utility.h"

#include <random>

double radianToDegree(double angle) {
	return angle * 180.0 / PI_;
}

double degreeToRadian(double angle) {
	return angle / 180.0 * PI_;
}

int random(int max) {
	return rand() % max;
}

int random(int min, int max) {
	return (rand() % (max - min)) + min;
}