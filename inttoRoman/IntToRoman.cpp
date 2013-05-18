#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string IntToRoman(int lhs) 
{
    string result;
    char romanChar[7] = {'M','D','C','L','X','V','I'};
    int romanInt[7] = {1000,500,100,50,10,5,1};

    int tmp = lhs;

    for(int i = 0; i < 7 && tmp;)
    {
	int divisor = tmp / romanInt[i];

	if(divisor)
	{
	    if(divisor <= 3)
	    {
		for(int j = 0;j < divisor; j++)
		{
		    result += romanChar[i];
		}
		tmp -= (int)(divisor * romanInt[i]);
	    }
	    else
	    {
		result += romanChar[i];
		result += romanChar[i-1];
		tmp -= (int)(divisor * romanInt[i]);
		i++;
	    }
	}
	else
	{
	    if(tmp >= (int)(0.9 * romanInt[i]))
	    {
		if(i == 1 || i == 3 || i == 5)
		{
		    result += romanChar[i+1];
		    result += romanChar[i];
		    tmp -= (int)(0.8 * romanInt[i]);
		    i++;
		}
		else
		{
		    result += romanChar[i+2];
		    result += romanChar[i];
		    tmp -= (int)(0.9 * romanInt[i]);
		    i += 2;
		}
	    }
	    else
	    {
		i++;
	    }
	}
    }

    return result;
}

int main()
{
    ofstream inf("int.txt",ios_base::app);

    if(!inf)
    {
	cerr << "Don't open your file" << endl;
	return -1;
    }

    for(int i = 1; i <= 3999; i++)
    {
	inf << IntToRoman(i) << " " << i << endl;
    }

    inf.close();

    return 0;
}
