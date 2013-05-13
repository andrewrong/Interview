#include <vector>
#include <map>
#include <iterator>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int,int> table;
        vector<int> result;

        for(int i = 0; i < numbers.size(); i++)
        {
            table[numbers[i]] = i;
        }

        for(int i = 0; i < numbers.size(); i++)
        {
	    int tmp = target - numbers[i];
	    map<int,int>::const_iterator iter;
	    if((iter = table.find(tmp)) != table.end())
	    {
		cout << "(" << i << "," << iter->second <<")" << endl;
		result.push_back(i+1);
		result.push_back(iter->second+1);
		break;
	    }
        }
	return result;
    }
};

int main()
{
    int arr[3] = {5,75,25};
    vector<int> numbers(arr,arr+3);
    
    Solution s;
    s.twoSum(numbers,100);
    return 0;
}
