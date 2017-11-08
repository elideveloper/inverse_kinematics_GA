#include "utility.h"

#include <random>

int radianToDegree(double angle) {
	return angle * 180 / 3.14;
}

double degreeToRadian(int angle) {
	return angle / 180.0 * 3.14;
}

int random(int max) {
	return rand() % max;
}

int random(int min, int max) {
	return (rand() % (max - min)) + min;
}