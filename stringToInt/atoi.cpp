#include <cstring>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int atoi(const char* lhs)
{
    char strInt[20] = {0};
    int length = strlen(lhs);
    bool hasSigned = 0; 
    int result = 0;
    int i = 0;

    for(i = 0; i < length && isspace(lhs[i]); i++)
	;
    
    cout << "i:" << i << endl;
    cout << "length:" << length << endl;

    if(i < length)
    {
	if(lhs[i] == '-')	
	{
	    hasSigned = 1;
	    i++;
	}
	else if(lhs[i] == '+')
	{
	    i++;
	}
	
	int strIntLength = 0;

	for(;i < length && isdigit(lhs[i]); i++)
	{
	    strInt[strIntLength++] = lhs[i];
	}

	for(int j = 0; j < strIntLength; j++)
	{
	    result += ((strInt[j] - '0') * pow(10,strIntLength - 1 - j));
	}
	
	if(result < 0 && hasSigned != 1)
	{
	    result = pow(2,31) - 1;
	}
	return result * (hasSigned ? -1 : 1);
    }
    else
    {
	return 0;
    }
}

int main()
{
    fstream of("string.txt",ios_base::in);

    if(!of)
    {
	cerr << "Don't open your file" << endl;
	return -1;
    }

    string str;
    
    while(of >> str)
    {
	cout << atoi(str.c_str()) << endl;
    }

    return 0;
}
