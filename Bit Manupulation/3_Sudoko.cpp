#include <iostream>
#include <cstring> // for memset;
using namespace std;
void display(int sudoko[9][9], int n)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sudoko[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;
	// return;
}
void solveSudoko(int sudoko[9][9], int row[9], int colum[9], int grid[3][3], int i, int j, int n)
{
	if (i == n)
	{
		display(sudoko, n);
		return;
	}
	if (sudoko[i][j] > 0)
	{ //don't do anithing to the  non-zero element
		solveSudoko(sudoko, row, colum, grid, (j == n - 1) ? i + 1 : i, (j == n - 1) ? 0 : j + 1, n);
	}
	else
	{
		for (int num = 1; num <= 9; num++)
		{
			if (
				(row[i] & (1 << num)) == 0 &&
				(colum[j] & (1 << num)) == 0 &&
				(grid[i / 3][j / 3] & (1 << num)) == 0

			)
			{ // On the bit
				sudoko[i][j] = num;
				row[i] ^= (1 << num);
				colum[j] ^= (1 << num);
				grid[i / 3][j / 3] ^= (1 << num);

				solveSudoko(sudoko, row, colum, grid, (j == n - 1) ? i + 1 : i, (j == n - 1) ? 0 : j + 1, n);

				// off the bit

				grid[i / 3][j / 3] ^= (1 << num);
				colum[j] ^= (1 << num);
				row[i] ^= (1 << num);
				sudoko[i][j] = 0;
			}
		}
	}
}

int main()
{
	int sudoko[9][9] = {
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 0, 0},
		{0, 0, 3, 0, 1, 0, 0, 0, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0},
	};
	int row[9];
	int colum[9];
	int grid[3][3];

	memset(row, 0, sizeof(row));
	memset(colum, 0, sizeof(colum));
	memset(grid, 0, sizeof(grid));
	int n = sizeof(row) / sizeof(row[0]);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			row[i] |= (1 << sudoko[i][j]);
			colum[j] |= (1 << sudoko[i][j]);
			grid[i / 3][j / 3] |= (1 << sudoko[i][j]);
		}
	}
	solveSudoko(sudoko, row, colum, grid, 0, 0, 9);

	return 0;
}