#ifndef RANGE_H
#define RANGE_H

class Range {
public:
	Range();
	Range(double max, double min);
	Range(const Range & range);
	double getRandom();
private:
	double _min;
	double _max;
};

#endif