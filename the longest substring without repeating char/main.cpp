#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int FindTheLongestSubstring(const string& lhs)
{
    int charArr[256] = {0};
    memset(charArr,0,sizeof(int) * 256);
    //int maxBegin = 0;
    int maxCount = 0;
    int length = lhs.size();
    int count = 0;

    for(int i = 0; i < length; i++)
    {
	for(int j = i; j < length; j++)
	{
	    if(charArr[static_cast<int>(lhs[j])] == 0)
	    {
	        count++;
	        charArr[static_cast<int>(lhs[j])] = 1;
	    }
	    else
	    {
	        if(count > maxCount)
	        {
	    	maxCount = count;
	        }
	        count = 1;
	        memset(charArr,0,sizeof(int) * 256);
	        charArr[static_cast<int>(lhs[j])] = 1;
	    }
	}

	if(count > maxCount)
	{
	    maxCount = count;
	}

	memset(charArr,0,sizeof(int) * 256);
	count = 0;
    }


    return maxCount;
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
	cout << FindTheLongestSubstring(str) << endl;
    }

    return 0;
}
