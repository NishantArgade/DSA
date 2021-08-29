#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	int n = bitset<8>("0011").to_ulong();
	int even = 0, odd = 0;
	for (int i = 0; i < 32; i++)
	{
		if (i % 2 == 0)
		{
			if ((n & (1 << i)) != 0)
			{
				even++;
			}
		}
		else
		{
			if ((n & (1 << i)) != 0)
			{
				odd++;
			}
		}
	}
	int bit = even - odd;
	(bit % 3 == 0) ? cout << "given Number is divisible by 3 " : cout << "given Number is Not divisible by 3 ";
	return 0;
}