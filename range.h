#ifndef RANGE_H
#define RANGE_H

class Range {
public:
	Range();
	Range(int max, int min);
	Range(const Range & range);
	int getRandom();
private:
	int _min;
	int _max;
};

#endif