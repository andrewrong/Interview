#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;
struct node
{
    char romanChar;
    int num;
};

int RomanToInt(string str)
{
    int length = str.size();
    int result = 0;
    map<char,int> m;
    m.insert(make_pair('M',1000));
    m.insert(make_pair('D',500));
    m.insert(make_pair('C',100));
    m.insert(make_pair('L',50));
    m.insert(make_pair('X',10));
    m.insert(make_pair('V',5));
    m.insert(make_pair('I',1));

    for(int i = length - 1; i >= 0; i--)
    {
	if((i+1) >= length)
	{
	    result += m[str[i]];
	}
	else
	{
	    if(m[str[i]] < m[str[i+1]])
	    {
		result -= m[str[i]];
	    }
	    else
	    {
		result += m[str[i]];
	    }
	}
    }

    return result;
}

int main()
{
    ifstream inf("int.txt",ios_base::in);

    if(!inf)
    {
	cerr << "Don't open your file" << endl;
	return -1;
    }

    string roman;
    int num;
    
    while(inf >> roman >> num)
    {
	if(RomanToInt(roman) == num)
	{
	    cout << true << endl;
	}
	else
	{
	    cout << false << endl;
	    cout << roman << " " << RomanToInt(roman) << " " << num << endl;
	}
    }
}
