#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

bool IsPalindrome(int lhs)
{
    int intLength = 0;
    int result = 0;
    int tmp = lhs; 
    
    if(lhs < 0)
    {
	return false;
    }

    do
    {
	intLength++;	
	tmp /= 10;
    }
    while(tmp);

    if(intLength % 2 == 0)
    {
	int mid = intLength / 2;
	tmp = lhs;
	for(int i = 0; i < mid; i++)
	{
	    int num = tmp % 10;
	    result += (num * pow(10,i)+ num * pow(10,intLength - 1 - i));
	    tmp /= 10;
	}
    }
    else
    {
	int mid = intLength / 2 + 1;
	
	tmp = lhs;

	for(int i = 0; i < (mid - 1); i++)
	{
	    int num = tmp % 10;
	    result += (num * pow(10,i) + num * pow(10,intLength - 1 - i));
	    tmp /= 10;
	}

	result += ((tmp % 10) * pow(10,mid - 1));
    }

    if(lhs == result)
    {
	return true;
    }
    else
    {
	return false;
    }
}

int main()
{
    fstream infile("int.txt",ios_base::in);

    if(!infile)
    {
	cerr << "Don't open your file" << endl;
	return -1;
    }

    int num = 0;

    while(infile >> num)
    {
	cout << num << endl; 
	cout << IsPalindrome(num) << endl;
    }

    return 0;
}
