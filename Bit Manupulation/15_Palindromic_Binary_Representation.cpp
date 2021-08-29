#include <iostream>
#include <bitset>
using namespace std;
int getReverse(int n)
{
	int rev = 0;
	while (n)
	{
		if (n & 1)
			rev |= 1;

		n >>= 1;
		rev <<= 1;
	}
	rev >>= 1;
	return rev;
}
int palindromic(int n)
{
	int count = 1, length = 1;
	while (count < n)
	{
		length++;
		int elesAtThatlength = ((1 << (length - 1) / 2));
		count += elesAtThatlength;
	}
	count -= (1 << (length - 1) / 2);
	int Offset = n - count - 1;

	int ans = (1 << (length - 1));
	ans |= (Offset << (length / 2));
	int part1 = ans;
	ans >>= (length / 2);
	int rev = getReverse(ans);
	ans = part1 | rev;
	return ans;
}
int main()
{

	cout << "The palendromic is : " << bitset<16>(palindromic(29)).to_string() << endl;
	return 0;
}