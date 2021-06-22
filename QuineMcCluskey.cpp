#include <iostream>
#include <stdint.h>
#include "functions.h"

using namespace std;

int main()
{
	uint16_t *ones, *one_size, *in_array, in_size;
	char input[1000000];

	//Getting the input as a string
	cout<<"Enter the Minterm input : ";
	cin>>input;

	//Allocating size for input array
	in_array = (uint16_t *)malloc(65536*sizeof(uint16_t));
	
	//Allocating size for 2D array to store number of ones
	ones = (uint16_t *)malloc(65536*16*sizeof(uint16_t));

	//Allocating size for array to store the size of 1D array of number of ones
	one_size = (uint16_t *)malloc(16*sizeof(uint16_t));

	//Converting input string to uint16_t array
	in_size = dataConversion(in_array,input);
	cout<<"Entered Array : ";
	for (int i=0;i<=in_size;i++)
	{
		cout<<*(in_array + i)<<"  ";
	}
	
	//Splitting based on number of ones
    split_ones(in_array, in_size, ones, one_size);
	free(in_array);

	//Printing the based on number of ones
	print_number_of_ones(ones, one_size);
	
	free(one_size);
	free(ones);
}