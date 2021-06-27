#include <iostream>
#include <stdint.h>
#include "functions.h"

using namespace std;

int main()
{
	/*
	uint8_t num;
	uint16_t val, *ones;
	char input[1000000];
	cout<<"Enter a value : ";
	cin>>val;
	num = number_of_ones(val);
	cout<<"The number of ones in "<<val<<" : "<<unsigned(num)<<"\n";
	cout<<"Enter the string input : ";
	cin>>input;
	ones = (uint16_t *)malloc(65536*sizeof(uint16_t));
	uint16_t size;
	size = dataConversion(ones,input);
	for(int i=0;i<=size;i++)
	{
		cout<<ones[i]<<"  ";
	}
	cout<<"\n";
	free(ones);
	*/
	
	/*
	uint16_t val;
	cout<<"Enter a value : ";
	cin>>val;
	bool output;
	output = is_pow_of_2(val);
	if(output)
	{
		cout<<"Yes, is power of 2\n";
	}
	else
	{
		cout<<"No, is not power of 2\n";
	}
	*/
	
	cout<<"Enter the size : ";
	int size;
	uint16_t *first, *second;
	cin>>size;
	first = (uint16_t *)malloc(1000*sizeof(uint16_t));
	second = (uint16_t *)malloc(1000*sizeof(uint16_t));
	cout<<"Enter set one numbers : ";
	for(int i=0;i<size;i++)
	{
		cin>>*(first + i);
	}
	cout<<"Enter set two numbers : ";
	for(int i=0;i<size;i++)
	{
		cin>>*(second + i);
	}
	if(is_compatible(first,second,size))
	{
		cout<<"The sets are compatible.";
	}
	else
	{
		cout<<"The sets are not compatible.";
	}
	free(first);
	free(second);
}























