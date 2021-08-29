#include <iostream>
#include <string>
#include <bitset> //for Binary Representation
using namespace std;

int copyBits(int A, int B, int R, int L)
{
	int k = 1 << (R - L + 1);
	k = k - 1;
	k = k << L;
	int mask = A & k;

	int ans = B | mask;
	return ans;
}
int main()
{
	int Right = 4, Left = 1;
	cout <<bitset<8>(copyBits(29,3,4,1));//31

	return 0;
}