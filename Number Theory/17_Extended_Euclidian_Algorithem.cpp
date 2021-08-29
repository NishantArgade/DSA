#define li long int
#define lli long long int
#define rfl(i, k, n) for (int i = k; i <= n; i++)
#define INF 1000000000
#define mod 1000000007

#include <iostream>
using namespace std;

int gcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

int main()
{
	int x = 1, y = 1;
	cout <<"GCD : "<< gcd(8, 2, x, y)<<endl;
cout<<" x : "<<x<<" y : "<<y<<endl;
	return 0;
}