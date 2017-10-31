#include <iostream>
#include <ctime>

#include "Generation.h"

using namespace std;

double radToDegree(double angle) {
	return angle * 180.0 / PI;
}


// consider claw 
// resolve mutation problem
// insert algorithm inside Maipulator and set range parameters
// think about assymetric ranges

int main() {

	srand(time(0));

	int numIter = 10000;
	double h = 20.0;
	double l1 = 30.0;
	double l2 = 15.0;
	double l3 = 12.0;
	Manipulator manip(l1, l2, l3, h, PIdiv2, PIdiv2, PIdiv2, PIdiv2);			// initial state is set automatically
	Point destPoint(1.0, 1.0, 1.0);
	Generation gen(10);
	const double mutateProb = 0.1;
	const int numLeaveBest = 2;
	const int numCrossover = 4;

	for (int i = 0; i < numIter; i++) {
		gen.turnToNext(manip, destPoint, numLeaveBest, numCrossover, mutateProb);
		//printf("\nCurr err: %.2f", manip.findError(*gen.getBestInd(), destPoint));
		//printf("\nTeta1: %.2f; Teta2: %.2f; Teta3: %.2f\n", gen.getBestInd()->teta1, gen.getBestInd()->teta2, gen.getBestInd()->teta3);
	}

	printf("\Final err: %.2f", manip.findError(*gen.getBestInd(), destPoint));
	printf("\n Alpha: %.2f; Teta1: %.2f; Teta2: %.2f; Teta3: %.2f\n", 
		radToDegree(gen.getBestInd()->alpha), radToDegree(gen.getBestInd()->teta1),
		radToDegree(gen.getBestInd()->teta2), radToDegree(gen.getBestInd()->teta3));
	printf("\nx: %.2f; y: %.2f; z: %.2f\n",
		manip.computeX(*gen.getBestInd()), 
		manip.computeY(*gen.getBestInd()), 
		manip.computeZ(*gen.getBestInd()));
	Individual rotInd = manip.getServoAngles(*gen.getBestInd());
	printf("\n Rotate on: %.2f; Teta1: %.2f; Teta2: %.2f; Teta3: %.2f\n",
		radToDegree(rotInd.alpha), radToDegree(rotInd.teta1),
		radToDegree(rotInd.teta2), radToDegree(rotInd.teta3));
	
	system("pause");
	return 0;
}