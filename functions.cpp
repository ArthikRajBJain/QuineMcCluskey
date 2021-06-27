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

void compute_tabulation(uint16_t *ones[], uint16_t *one_size[], uint16_t *not_done, uint16_t *not_done_size, bool *done)
{
	int i=0,j=0,k=0,l=0;
	for(i=1;i<16;i++)
	{
		ones[i] = (uint16_t *)malloc(65536*16*sizeof(uint16_t));
		one_size[i] = (uint16_t *)malloc(16*sizeof(uint16_t));
		for(l=0;l<16;l++)
		{
			*(one_size[i] + l) = 0;
		}
		for(j=0;j<(16-i);j++)
		{
			*(ones[i-1] + (16-i)*j + *(one_size[i-1] + k));
		}
		free(ones[i-1]);
		free(one_size[i-1]);
	}
	free(ones[15]);
	free(one_size[15]);
}

bool is_compatible(uint16_t *first, uint16_t *second, uint8_t size)
{
	uint16_t val, or1 = 0, or2 = 0;
	int i;
	for(i=0;i<size;i++)
	{
		or1 = or1 | *(first + i);
		or2 = or2 | *(second + i);
	}
	val = or1 ^ or2;
	if(is_pow_of_2(val))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool is_pow_of_2(uint16_t val)
{
	uint16_t mask = 1;
	bool flag = 0;
	for(int i=0;i<=16;i++)
	{
		if(mask == val)
		{
			flag = 1;
		}
		mask = mask << 1;
	}
	return flag;
}

















