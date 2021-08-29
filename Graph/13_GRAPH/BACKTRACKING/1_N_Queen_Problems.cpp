
// given the "n" Queens arrange them such that no row ,column and Diagonal attack happend amongs Them.
// using BackTracking Approch.
#include <iostream>
using namespace std;
bool isSafeplace(int board[][4], int i, int j, int n)
{
    for (int row = 0; row < i; row++) // check previous queen's Attack  upto current Queen .
    {
        if (board[row][j] == 1) // check if any column Attack exists
            return false;

        //  check if any left digonal Attack exists
        int x = i;
        int y = j;
        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 1)
                return false;
            x--;
            y--;
        }
        //  check if any Right digonal Attack exists
        x = i;
        y = j;
        while (x >= 0 && y < n)
        {
            if (board[x][y] == 1)
                return false;
            x--;
            y++;
        }
    }
    //for all above case is not satisfied,then retrun true,means No any Type of Attack exists.
    return true;
}
bool solveNQueen(int board[][4], int i, int n)
{
    // Base Case :
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                    cout << "Q"<<i+1<<" ";
                else
                    cout << "- ";
            }
            cout<<endl;
        }
            cout<<"\nMirror image of our Solution is : "<<endl;

    }
    // Recursive Case.
    //Try to placed the Queen in Right place(position) in current row.
    for (int j = 0; j < n; j++)
    {
        if (isSafeplace(board, i, j, n))
        {
            board[i][j] = 1; // means,we wil placed i,j in right position
            bool isplacedNextQueen = solveNQueen(board, i + 1, n);

            if (isplacedNextQueen)
                return true;

            // BackTracking is perform here =>
            board[i][j] = 0; // means,our Assumption for i,j position is not right
        }
    }
    return false; // means, you have to tried all position  in current row but could'nt placed the queen in right position(i.e Attack may be happend for all places in the current row).
}
int main()
{
    int n;
    cout<<"Enter Queen numbers : "<<endl;
    cin >> n;

    int board[4][4] = {0};
    solveNQueen(board, 0, n);
    return 0;
}