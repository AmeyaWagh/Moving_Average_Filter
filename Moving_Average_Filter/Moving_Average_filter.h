#ifndef MOVING_AVERAGE_FILTER
#define MOVING_AVERAGE_FILTER
#include "Arduino.h"

#define average 1
#define median 2

class Averaging_Filter
{
	public:
	Averaging_Filter();
	float LowPassFilter(float x, int y);
	int len = 10;
	float buff[10];
	
	private:
	float sum = 0;
	float avrg = 0;
	float medn = 0;
	float temp = 0;
};



#endif