#define li long int
#define lli long long int
#define FLoop for (int i = 0; i < n; i++)
#define INF 1000000000
// #define mod 1000000007

#include <iostream>
using namespace std;
int res = 1;
lli pow(lli x, lli n,lli mod)
{
	while (n)
	{
		if (n % 2)
			res = ((res) % mod * (x) % mod) % mod;
		x = ((x) % mod * (x) % mod) % mod;
		n /= 2;
	}
	return res;
}
int main()
{//739066146
	// Calculate last digit of 1378^2
	//Modular Aproch:
	// find congarance of 1378 which is 8 under mdulo 10
	//then  find 8^2
	cout<<pow(8, 2,10);
	
	return 0;
}