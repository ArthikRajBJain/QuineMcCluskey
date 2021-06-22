#include "functions.h"
#include <iostream>
#include <stdint.h>

using namespace std;

uint16_t dataConversion(uint16_t *data,char *str)
{
    uint16_t j = 0;
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if((str[i] == ',') && (str[i+1] != '\0'))
        {
            j++;
            i++;
    	}
    	if(str[i] != ',')
    	{
    		data[j] = data[j]*10 + int(str[i])-48;
  		}
  	}
  	return j;
}

uint8_t number_of_ones(uint16_t num)
{
	uint8_t count = 0;
	uint16_t mask = 1;
	for(int i=0;i<16;i++)
	{
		if(mask & num)
		{
			count++;
		}
		mask = mask << 1;
	}
	return(count);
}

void split_ones(uint16_t *in_array, uint16_t in_size, uint16_t *ones, uint16_t *one_size)
{
	for(int i=0;i<16;i++)
	{
		*(one_size + i) = 0;
	}
	for(int i=0;i<=in_size;i++)
	{
		*(ones + 16*number_of_ones(*(in_array + i)) + *(one_size + number_of_ones(*(in_array + i)))) = *(in_array + i);
		*(one_size + number_of_ones(*(in_array + i))) += 1;
	}
}

void print_number_of_ones(uint16_t *ones, uint16_t *one_size)
{
	cout<<"\n----------------------------------------------------\n";
	cout<<"Number\t"<<"Values";
	cout<<"\n----------------------------------------------------\n";
	for(int i=0;i<16;i++)
	{
		cout<<i<<"\t";
		for(int j=0;j<*(one_size + i);j++)
		{
			cout<<*(ones + 16*i +j)<<"  ";
		}
		cout<<"\n----------------------------------------------------\n";
	}
}