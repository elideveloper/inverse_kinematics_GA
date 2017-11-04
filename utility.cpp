#include "utility.h"

#include <random>

double radianToDegree(double angle) {
	return angle * 180.0 / PI_;
}

double degreeToRadian(double angle) {
	return angle / 180.0 * PI_;
}
// DELETE
int random(int max) {
	return rand() % max;
}