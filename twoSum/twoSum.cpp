#include <iostream>
#include <utility>
#include <map>
#include <iterator>

using namespace std;

pair<int,int> TwoSum(int* array,int size,int target)
{
    map<int,int> table;

    for(int i = 0; i < size; i++)
    {
	table[array[i]] = i;
    }

    for(int i = 0; i < size; i++)
    {
	int tmp = target - array[i];
	map<int,int>::const_iterator iter;
	if((iter = table.find(tmp)) != table.end())
	{
	    return make_pair(i,iter->second);
	}
    }

    return make_pair(0,0);
}

int main()
{
    int array[5] = {2,5,3,7,10};
    pair<int,int> tmp = TwoSum(array,5,13);

    if(tmp.first == 0 && tmp.second == 0)
    {
	cout << "I can't make target " << endl;
    }
    else
    {
	cout << "Index1=" << tmp.first << ", Index2=" << tmp.second << endl;
    }

    return 0;
}
