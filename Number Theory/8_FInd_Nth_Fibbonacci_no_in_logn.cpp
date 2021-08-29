#include <iostream>
using namespace std;

#define RFL(i, N) for (int i = 0; i < N; i++)
#define N 2
#define lli long long int

lli A[N][N], I[N][N], T[N][N];

void multi(lli A[][N], lli B[][N])
{
	int res[N][N];

	RFL(i, N)
	{
		RFL(j, N)
		{
			res[i][j] = 0;

			RFL(k, N)
			res[i][j] += (A[i][k] * B[k][j])% 100000L;
		}
	}
	RFL(i, N)
	RFL(j, N)
	A[i][j] = res[i][j];
}
int getFib(lli A[][N], lli n)
{
	if (n <= 2)
		return A[0][n-1];

	RFL(i, N)
	RFL(j, N)
	if (i == j)
		I[i][j] = 1;
	else
		I[i][j] = 0;

	T[0][0] = 0, T[0][1] = T[1][0] = T[1][1] = 1;

	n = n - 1;
	while (n > 0)
	{
		if (n % 2)
			multi(I, T);

		n /= 2;
		multi(T, T);
	}

	int Fn = A[0][0] * I[0][0] + A[0][1] * I[1][0];
	return Fn;
}
int main()
{
	cout << "Enter 1 and 2 Fibbonacii no :" << endl;
	cin >> A[0][0] >> A[0][1];

	int n;
	cout << "Which Fiibbo no you want to calculate :" << endl;
	cin >> n;

	cout << "The Fibbonacii Number is :" << getFib(A, n);
	return 0;
}