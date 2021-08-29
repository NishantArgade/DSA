#include <iostream>
using namespace std;

#define n 5
void printOptimalBST(int Weight[n][n], int Cost[n][n], int Root[n][n])
{

    cout << "\nThe Optimal BST is " << endl;
    cout << "\nThe Weights for Unsuccessful Search is :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "| " << Weight[i][j] << " |";

        cout << endl;
    }
    cout << "\nThe Min Cost for Binary Searching is :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)

            cout << "| " << Cost[i][j] << " |";

        cout << endl;
    }
    cout << "\nThe roots for Construct Optimal BST is :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "| " << Root[i][j] << " |";

        cout << endl;
    }
}
void OptimalBST(int Weight[n][n], int Cost[n][n], int Root[n][n], int p[n], int q[n])
{
    for (int dig = 1; dig < n; dig++)
    {

        for (int i = 0; i < n; i++)
        {
            int min = 999999999, t;
            for (int j = 0; j < n; j++)
            {

                if (j - i == dig)
                {
                    Weight[i][j] = Weight[i][j - 1] + p[j] + q[j];

                    for (int k = i + 1; k <= j; k++)
                    {
                        t = Cost[i][k - 1] + Cost[k][j];

                        if (t < min)
                        {
                            min = t;
                            Cost[i][j] = t + Weight[i][j];
                            Root[i][j] = k;
                        }
                    }
                }
            }
        }
    }
    printOptimalBST(Weight, Cost, Root);
}
int main()
{ /* Q. Find Optimal BST ?
  Optimal BST :

  Rules:
  1) Optimal Binary Search tree is that tree whoes Searching time is less(min).
  2) if have n nodes then 2nCn\n+1(catelon number formula) Trees are possible
 3) Among this Different BST you have to choose Optimal BST.
 
 ex   3       3        2           1     1
     /       /        / \           \     \
    2       1        1   3          3      2
   /         \                     /        \
  1           2       OBST        2          3
 (1)         (2)      (3)        (4)       (5)
T Com->3    ->3      ->2        ->3       ->3
 
 BST ( Root is 2 ) Total Comparison is min so that it is Optimal BST that way Searching Cost is less

         */
    int Weight[n][n] = {0};
    int Cost[n][n] = {0};
    int Root[n][n] = {0};

    int p[n] = {00, 3, 3, 1, 1};
    int q[n] = {2, 3, 1, 1, 1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (j - i == 0)
            {
                Weight[i][j] = q[j];
                Cost[i][j] = 0;
                Root[i][j] = 0;
            }
        }
    }
    OptimalBST(Weight, Cost, Root, p, q);
    return 0;
}