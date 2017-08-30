
#include"Moving_Average_filter.h"
#include "Arduino.h"

Averaging_Filter::Averaging_Filter()
{
	len = 10;
	float buff[10] = {0};
	sum = 0;
	avrg = 0;
	medn = 0;
	temp = 0;
}

float Averaging_Filter::LowPassFilter(float x, int y)
{
	if(y == 1)
	{
		sum = 0;
		avrg = 0;
		for(int i = 0; i < len-1;i++)
		{
			buff[i] = buff[i+1];
			sum = sum+buff[i];
		}
		buff[len-1] = x;
		sum = sum+x;
		avrg = sum/len;
		return avrg;
	}
	
	else if(y == 2)
	{
		medn = 0;
		avrg = 0;
		for(int i = 0; i < len-1;i++)
		{
			buff[i] = buff[i+1];
		}
		buff[len-1] = x;
		
		for(int i = 0; i < len;i++)
		{
			for(int j = 0; j < len-1;j++)
			{
				if(buff[j] > buff[j+1])
				{
					temp = buff[j+1];
					buff[j+1]=buff[j];
					buff[j] = temp;
				}
			}
		}
		avrg = (buff[len/2]+buff[(len/2)-1])/2;
		return avrg;
			
	}
	
}