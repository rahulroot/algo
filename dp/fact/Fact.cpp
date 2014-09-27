#include <iostream>
#include <fstream>
using namespace std;
typedef unsigned long long int ull;

ull table[50] = {0};

void pre_cal()
{
	table[0] = 1;
	table[1] = 1;
	int i;
	for(i=2; i < 200; ++i)
    table[i] = table[i-1]*i;
}


int main()
{

	pre_cal();
	unsigned int num;
	ifstream infile;
	infile.open("./sample.txt");
	while( infile >> num )
	{
    if(num > 50)
      cout <<"Use another program BigIntFact.cpp to calculate the factorial using BigInt Mechanism." << endl;
    else
		  cout << table[num] << endl;
	}

	return 0;
}
