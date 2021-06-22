#include <iostream>
#include <stdint.h>
#include "functions.h"

using namespace std;

int main()
{
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
}