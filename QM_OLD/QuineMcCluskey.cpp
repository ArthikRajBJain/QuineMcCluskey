#include<iostream>
using namespace std;

//integer to binary conversion
unsigned long int intToBinary(int value)
{
  int arr[100],binary=0;
  int i=-1;
  while(value!=0)
  {
    i++;
    arr[i]=value%2;
    value=value/2;
  }
  while(i!=-1)
  {
    binary=binary*10+arr[i];
    i--;
  }
  return binary;
}

//number of ones in the binary form of the number
int numberOfOnes(int value)
{
  int number=0;
  while(value!=0)
  {
    if(value%2==1)
    {
      number++;
    }
    value=value/2;
  }
  return number;
}

//string data to integer array data conversion
int dataConversion(int *data,char *str)
{
  int j=0,i;
  for(i=0;str[i]!='\0';i++)
  {
    if(str[i]==',')
    {
      j++;
      i++;
    }
    data[j]=data[j]*10+int(str[i])-48;
  }
  if(str[i-2]==',')
  {
    data[j]=0;
    j--;
  }
  return j;
}

//power of number
unsigned long int power(int num,int power)
{
  int ans=1;
  for(int i=0;i<power;i++)
  {
    ans=ans*num;
  }
  return ans;
}

//data validation
int dataValidationAndProcessing(int bits,int *data,char *str,int *flag)
{
  int valid,cnt;
  valid=power(2,bits);
  cnt=dataConversion(data,str);
  for(int i=0;i<=cnt;i++)
  {
    if(data[i]>=valid)
    {
      *flag=-1;
    }
    else
    {
      *flag=1;
    }
  }
  return cnt;
}

//global variables

//truth table data in string
char str[10000];
//truth table data
int data[10000]={0};
//data sorted  based on number of ones one[number of ones][data with that number of ones]
int one[100][100];
int oneindex[100]={0};
//structure for storing flag data, grouping data and OR data
//flag for all the groups flag[page number][group number][element number]
int flag[100][100][100];
//elements of all the groups elements[page number][group number][element number][elements of that group]
int elements[100][100][100][100];
//weights in common between elements weights[page number][group number][element number]
int weights[100][100][100];
int OR[100][100][100];
//counting number of groups in page groupNumber[page number]
int groupNumber[100]={0};
//counting number of elements in each group elementNumber[page number][group number]
int elementNumber[100][100];

int main()
{

  ///Data Acquisition///
  int bits,fl=0;
  cout<<"Enter the number of variables to be solved using Quine McCluskey Method : ";
  cin>>bits;
  cout<<"Enter the truth table data separated with comma(,)\n";
  cin>>str;
  int cnt;
  cnt=dataValidationAndProcessing(bits,data,str,&fl);
  if(fl==1)
  {
    cout<<"Entered data is : \n";
    for(int i=0;i<=cnt;i++)
    {
      cout<<data[i]<<"  ";
    }
  }
  else
  {
    cout<<"Invalid data entered, data cannot be greater than or equal to "<<power(2,bits);
  }


  ///Sorting according to number of Ones///
  int ones;
  for(int i=0;i<=cnt;i++)
  {
    ones=numberOfOnes(data[i]);
    one[ones][oneindex[ones]]=data[i];
    oneindex[ones]++;
  }
  for(int i=0;i<=bits;i++)
  {
    cout<<"\n"<<i<<" ONES : ";
    for(int j=0;j<oneindex[i];j++)
    {
      cout<<one[i][j]<<"  ";
    }
  }
  for(int i=bits;i>=0;i--)
  {
    if(oneindex[i]>0)
    {
      groupNumber[0]=i;
      break;
    }
  }
  for(int i=0;i<=groupNumber[0];i++)
  {
    elementNumber[0][i]=oneindex[i];
  }

  ///Grouping and flagging the selected minterms///
  int match;
  //loop for changing groups
  for(int i=0;i<=bits;i++)
  {
    //loop for changing the element number of group
    for(int j=0;j<oneindex[i];j++)
    {
      elements[0][i][j][0]=one[i][j];
      weights[0][i][j]=0;
      OR[0][i][j]=0;
      flag[0][i][j]=0;
    }
  }
  int num=0;
  //outer loop for controlling page
  for(int i=0;i<=bits;i++)
  {
    //loop for controlling groups
    for(int j=0;j<groupNumber[i];j++)
    {
      //loop to control element number
      for(int k=0;k<elementNumber[i][j];k++)
      {

      }
    }
  }






}
