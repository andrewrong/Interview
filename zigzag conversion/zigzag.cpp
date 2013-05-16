#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string convert(const string& lhs,int rows)
{
    if(rows == 1)
    {
	return lhs;
    }

    string result;
    int length = lhs.size();
    int interval = (rows - 1) * 2;
    
    for(int i = 0; i < rows; i++)
    {
	if(i == 0 || i == (rows - 1))
	{
	    for(int j = i; j < length; j += interval)
	    {
		result += lhs[j];
	    }
	}
	else
	{
	    int interval1 = (i * 2);
	    
	    for(int j = i; j < length; j += interval1)
	    {
		result += lhs[j];
		interval1 = interval - interval1;
	    }
	}
    }

    return result;
}

int main()
{
    fstream infile("string.txt",ios_base::in);

    if(!infile)
    {
	cerr << "Don't open your file" << endl;
	return -1;
    }

    string str;
    int rows;
    while(infile >> str >> rows)
    {
	cout << rows << endl;
	cout << convert(str,rows) << endl;
    }

    return 0;
}
