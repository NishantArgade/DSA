#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		GCD(b, a % b);
}
int main()
{
	// Euclidian Divide Algorithem for calculate GCD in log(n)
	cout << GCD(8, 4);

	return 0;
}