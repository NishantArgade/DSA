#include <iostream>
#include <string> //for to_string()
using namespace std;

void ChessBoard(int board[][4], int colum, int nDig, int rDig, int row, int n, string asf)
{
	if (row == n)
	{
		cout << asf << "." << endl;
		return;
	}
	for (int col = 0; col < n; col++)
	{

		if (
			(colum & (1 << col)) == 0 &&
			(nDig & (1 << (row + col))) == 0 &&
			(rDig & (1 << (row - col + n - 1))) == 0

		)
		{ // set bit is On
			board[row][col] = 1;
			colum ^= (1 << col);
			nDig ^= (1 << (row + col));
			rDig ^= (1 << (row - col + n - 1));

			ChessBoard(board, colum, nDig, rDig, row + 1, n, asf + (to_string(row) + "-" + to_string(col) + ", "));

			// set bet is off
			rDig ^= (1 << (row - col + n - 1));
			nDig ^= (1 << (row + col));
			colum ^= (1 << col);
			board[row][col] = 0;
		}
	}
}

int main()
{
	int board[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},

	};
	int colum = 0;
	int nDig = 0;
	int rDig = 0;
	int Quin = 4;
	ChessBoard(board, colum, nDig, rDig, 0, Quin, "");

	return 0;
}