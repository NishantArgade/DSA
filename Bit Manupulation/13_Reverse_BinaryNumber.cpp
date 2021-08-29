#include <iostream>
#include <bitset>
using namespace std;
int Reverse_Bits(int n)
{
	int flag = 0;
	int rev = 0, j = 0;
	for (int i = 31; i >= 0; i--)
	{
		if (flag) //found 1'st one bit
		{
			if ((n & (1 << i)) != 0)
			{ //bit is on
				// cout << 1;
				rev |= (1 << j);
			}
			else
			{ // bit is off
				// cout << 0;
			}
			j++;
		}
		else
		{ // not found 1'st one bit
			if ((n & (1 << i)) != 0)
			{ //bit is on
				flag = 1;
				// cout << 1;
				rev |= (1 << j);
				j++;
			}
			else
			{ // bit is off
			}
		}
	}
	return rev;
}
int main()
{ int n = 10;
  cout<<"Binary Num :"<<bitset<8>(n).to_string()<<endl;
	cout << "Reverse Given Binary Number is : " << bitset<8>(Reverse_Bits(10)).to_string();
	 return 0;
}