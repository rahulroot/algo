#include <iostream>
#include <fstream>
using namespace std;
typedef unsigned long long int ull;

ull table[101] = {0};

void pre_cal()
{
	table[0] = 0;
	table[1] = 1;
	int i;
	for(i=2; i < 101; ++i)
    table[i] = table[i-1] + table[i-2];
}


int main()
{

	pre_cal();
	unsigned int num;
	ifstream infile;
	infile.open("./sample.txt");
	while( infile >> num )
	{
    if(num > 100)
      cout <<"Use another program BigIntFab.cpp to calculate the fabonacci number using BigInt Mechanism." << endl;
    else
		  cout << table[num] << endl;
	}

	return 0;
}
