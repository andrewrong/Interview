#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int ReverseInteger(int lhs)
{
    int digits[20] = {0};
    int length = 0;
    bool hasSigned = lhs < 0 ? 1 : 0;
   
    lhs = abs(lhs);

    while(lhs)
    {
	int reminder = lhs % 10;
	digits[length++] = reminder;
	lhs /= 10;
    }
    
    int result = 0;

    for(int i = 0; i < length; i++)
    {
	result += (digits[i] * pow(10,length - 1 - i));
    }

    return result * (hasSigned ? -1 : 1);
}

int main()
{
    fstream of;
    of.open("int.txt",ios_base::in);

    if(!of)
    {
	cerr << "Don't open your file" << endl;
	return -1;
    }
    int inputNum = 0;
    while(of >> inputNum)
    {
	cout << ReverseInteger(inputNum) << endl;
    }

    return 0;
}
