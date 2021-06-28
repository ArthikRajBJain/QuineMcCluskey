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
		*(ones + (65536)*number_of_ones(*(in_array + i)) + *(one_size + number_of_ones(*(in_array + i)))) = *(in_array + i);
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
			cout<<*(ones + (65536)*i +j)<<"  ";
		}
		cout<<"\n----------------------------------------------------\n";
	}
}

void compute_tabulation(uint16_t *ones[], uint16_t *one_size[], uint16_t *not_done, uint16_t *not_done_size, bool *done)
{
	int i=0,j=0,k=0,l=0;
	uint32_t div, div2, po2;
	for(i=1;i<16;i++)
	{
		cout<<"\n====================================================\n";
		cout<<"Allocated ones["<<i<<"] and one_size["<<i<<"]\n";
		ones[i] = (uint16_t *)malloc(65536*16*sizeof(uint16_t));
		one_size[i] = (uint16_t *)malloc(16*sizeof(uint16_t));
		div = 65536*16/(17-i);
		div2 = 65536*16/(16-i);
		po2 = pow_2(i-1);
		for(int i1=0;i1<16;i1++)
		{
			*(one_size[i] + i1) = 0;
		}
		for(j=0;j<(16-i);j++)
		{
			for(k=0;k<(*(one_size[i-1]+j)/po2);k++)
			{
				for(l=0;l<(*(one_size[i-1]+j+1)/po2);l++)
				{
					if(is_compatible((ones[i-1] + div*j + k*po2), (ones[i-1] + div*(j+1) + l*po2), po2))
					{
						//sort_in_order((ones[i-1] + div*j + k*po2), (ones[i-1] + div*(j+1) + l*po2), po2);
						print_status((ones[i-1] + div*j + k*po2), (ones[i-1] + div*(j+1) + l*po2), po2);
						save_in_memory((ones[i-1] + div*j + k*po2), (ones[i-1] + div*(j+1) + l*po2), (ones[i] + div2*j + *(one_size[i] + j)), po2);
						*(one_size[i] + j) = *(one_size[i] + j) + 2*po2;
					}
				}
			}
			cout<<"\n----------------------------------------------------\n";
		}
		free(ones[i-1]);
		free(one_size[i-1]);
		cout<<"Freed ones["<<i-1<<"] and one_size["<<i-1<<"]\n";
		cout<<"\n====================================================\n";
	}
	free(ones[15]);
	free(one_size[15]);
	cout<<"Freed ones[15] and one_size[15]\n";
}

bool is_compatible(uint16_t *first, uint16_t *second, uint8_t size)
{
	uint16_t orr, xorr, or1 = 0, or2 = 0, xor1 = 0, xor2 = 0;
	int i;
	for(i=0;i<size;i++)
	{
		or1 = or1 | *(first + i);
		or2 = or2 | *(second + i);
		xor1 = xor1 ^ *(first + i);
		xor2 = xor2 ^ *(second + i);
	}
	orr = or1 ^ or2;
	if((xor1 == 0) && (xor2 == 0))
	{
		return 0;
	}
	xorr = xor1 ^ xor2;
	if(is_pow_of_2(orr) && is_pow_of_2(xorr))
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
	//Returns true even if the val is ZERO
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

void save_in_memory(uint16_t *first, uint16_t *second, uint16_t *destination, uint8_t size)
{
	int i;
	for(i=0;i<size;i++)
	{
		*(destination + i) = *(first + i);
		*(destination + size +i) = *(second + i);
	}
}

void print_status(uint16_t *first, uint16_t *second, uint8_t size)
{
	for(int i=0;i<size;i++)
	{
		cout<<*(first + i)<<" ";
	}
	for(int i=0;i<size;i++)
	{
		cout<<*(second + i)<<" ";
	}
	cout<<"\n";
}

int pow_2(int i)
{
	int out=1;
	if(i == 0)
	{
		return out;
	}
	for(;i>0;i--)
	{
		out *= 2;
	}
	return out;
}

void sort_in_order(uint16_t *first, uint16_t *second, uint8_t size)
{
	int i;
	uint16_t *p;
	p = (uint16_t *)malloc(size*2*sizeof(uint16_t));
	save_in_memory(first, second, p, size);
	selectionSort(p, size*2);
	for(i=0;i<size;i++)
	{
		*(first + i) = *(p + i);
		*(second + i) = *(p + size + i);
	}
	free(p);
}

void swap(uint16_t *xp, uint16_t *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(uint16_t arr[], uint8_t n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}














