#include <iostream>
using namespace std;

#define RFL(i, n) for (int i = 0; i < n; i++)
#define N 101

int A[N][N], I[N][N];

void Display(int A[][N], int dim)
{

	RFL(i, dim)
	{
		RFL(j, dim)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
void multi(int A[][N], int B[][N], int dim)
{
	int res[dim][dim];
	RFL(i, dim)
	{
		RFL(j, dim)
		{
			res[i][j] = 0;

			RFL(k, dim)
			res[i][j] += A[i][k] * B[k][j];
		}
	}
	RFL(i, dim)
	RFL(j, dim)
	A[i][j] = res[i][j];
}
void matrixMulti(int A[][N], int dim, int n)
{
	RFL(i, dim)
	RFL(j, dim)
	if (i == j)
		I[i][j] = 1;
	else
		I[i][j] = 0;

	RFL(i, n)
	while (n > 0)
	{
		if (n % 2)
			multi(I, A, dim);

		n /= 2;
		multi(A, A, dim);
	}
	Display(I, dim);
}
int main()
{
	int dim, p;
	cout << "Enter Dimention and Power :" << endl;
	cin >> dim >> p;

	RFL(i, dim)
	RFL(j, dim)
	cin >> A[i][j];

	matrixMulti(A, dim, p);
7
	return 0;
}