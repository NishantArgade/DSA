#include <iostream>
#include <bitset> // for binary to decimal
using namespace std;

int main()
{
	// bitset<32> bits("1011");
	//   int decimal = bits.to_ulong();
	//   cout<<"Decimal representation :"<<decimal<<endl;

	int n = bitset<8>("1010").to_ulong();

// int n =10;
// cout<<n;

	int Omask = 0xAA;
	int Emask = 0x55;
	int odd = (n & Omask);
	int even = (n & Emask);

	odd >>= 1;// 0101010
	even <<= 1;//01010101

	n = odd | even;

	cout << "After swaping positive and negative position bits :" << bitset<8>(n).to_string() << endl;


	return 0;
}