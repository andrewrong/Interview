#include <iostream>
#include <fstream>

using namespace std;

int TheMedianOfTwoSortedArrays(int A[],int m,int B[],int n)
{
    if(m == 1 && n ==  1)
    {
	return (A[0] >= B[0] ? A[0] : B[0]);
    }

    if(m == 0)
    {
	return B[n/2];
    }

    if(n == 0)
    {
	return A[m/2];
    }

    int aM = m / 2;
    int bM = n / 2;

    if(A[aM] > B[bM])
    {
	if(bM == 0)
	{
	    TheMedianOfTwoSortedArrays(A,aM,&B[bM],1);
	}
	else
	{
	    TheMedianOfTwoSortedArrays(A,aM,B,aM);
	}
    }
    else if(A[aM] < B[bM])
    {
    }
    else
    {
	return A[aM];
    }
}

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

	cout << TheMedianOfTwoSortedArrays(A,aNum,B,bNum) << endl;

	delete[] A;
	delete[] B;
    }

    return 0;
}
