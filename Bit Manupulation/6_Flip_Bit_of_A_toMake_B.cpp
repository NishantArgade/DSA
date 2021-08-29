#include <iostream>
using namespace std;

int flip_Bits(int A, int B)
{
	int C = (A ^ B);
	int count = 0;
	while (C != 0)
	{
		int mask = C & (-C);
		C = C - mask;
		count++;
	}
	return count;
}
int main()
{
   cout<<"Flip bits of A to make B you need to Flip bits is : "<<flip_Bits(13,3)<<endl;
	return 0;
}