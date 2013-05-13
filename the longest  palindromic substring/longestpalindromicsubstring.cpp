#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string FindLongestPalindromicSubstring(const string& desString)
{
    int length = desString.size();
    int subBegin = 0;
    int subEnd = 0;
    int maxBegin = 0;
    int maxEnd = 0;
    int maxCount = 0;

    for(int i = 0; i < length; i++)
    {
	subBegin = i - 1;
	subEnd = i + 1;
	while(subBegin >= 0 && subEnd < length)
	{
	    if(desString[subBegin] == desString[subEnd])
	    {
		subBegin--;
		subEnd++;
	    }
	    else
	    {
		break;
	    }
	}

	if((subEnd - subBegin - 1) > maxCount)
	{
	    maxBegin = subBegin + 1;
	    maxEnd = subEnd - 1;
	    maxCount = maxEnd - maxBegin + 1;
	}

	//other case
	
	subBegin = i;
	subEnd = i + 1;

	while(subBegin >= 0 && subEnd < length)
	{
	    if(desString[subBegin] != desString[subEnd])
	    {
		break;
	    }

	    subBegin--;
	    subEnd++;
	}

	if((subEnd - subBegin - 1) > maxCount)
	{
	    maxBegin = subBegin + 1;
	    maxEnd = subEnd - 1;
	    maxCount = maxEnd - maxBegin + 1;
	}
    }

    return desString.substr(maxBegin,maxCount);
}

int main()
{
    fstream of;
    of.open("string.txt",ios_base::in);
    string inputString;
    
    if(!of)
    {
	cerr << "Don't open your file" << endl;
	return -1;
    }

    while(of >> inputString)
    {
	cout << FindLongestPalindromicSubstring(inputString) << endl;
    }

    return 0;
}
