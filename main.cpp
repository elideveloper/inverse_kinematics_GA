#include <iostream>
#include <ctime>

#include "Generation.h"

using namespace std;

int main() {

	srand(time(0));

	int numIter = 10000;
	Manipulator manip(10.0, 5.0, 3.0);
	Point destPoint(6.6, 6.6, 10.0);
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
	printf("\n; Alpha: %.2f; Teta1: %.2f; Teta2: %.2f; Teta3: %.2f\n", gen.getBestInd()->alpha, gen.getBestInd()->teta1, gen.getBestInd()->teta2, gen.getBestInd()->teta3);
	printf("\nx: %.2f; y: %.2f; z: %.2f\n", manip.computeX(*gen.getBestInd()), manip.computeY(*gen.getBestInd()), manip.computeZ(*gen.getBestInd()));
	
	system("pause");
	return 0;
}