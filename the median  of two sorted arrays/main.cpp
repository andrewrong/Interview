#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int aNum = 0;
    int bNum = 0;

    ifstream infile("int.txt",ios_base::in);

    if(!infile)
    {
	cerr << "Don't open your file" << endl;

	return -1;
    }

    while(infile >> aNum >> bNum)
    {
	int *A = new int[aNum]();
	int *B = new int[bNum]();

	//这部分可以使用istream_iterator实现
	for(int i = 0; i < aNum; i++)
	{
	    infile >> A[i];
	}

	for(int i = 0; i < bNum; i++)
	{
	    infile >> B[i];
	}

	cout << Find_Media_Random_Length(A,aNum,B,bNum) << endl;

	delete[] A;
	delete[] B;
    }

    return 0;
}
