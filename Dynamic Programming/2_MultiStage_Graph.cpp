#include <iostream>
using namespace std;

#define n 9
#define stage 4

void PrintMinCostPath(int Path[n])
{
    cout << "\nMinimum cost path for given Graph is :" << endl;
    for (int i = 1; i <= stage; i++)
    {
        cout << Path[i] << " ";
    }
}
void MinPathInMultiStageGp(int Graph[][n], int MinCost[n], int NextVertex[n], int Path[n])
{
    MinCost[n - 1] = 0;

    for (int i = n - 2; i >= 1; i--)
    {
        int min = 9999999;

        for (int k = i + 1; k <= n - 1; k++)
        {
            if (Graph[i][k] != 0 && (Graph[i][k] + MinCost[k]) < min)
            {
                min = Graph[i][k] + MinCost[k];
                MinCost[i] = min;
                NextVertex[i] = k;
            }
        }
    }
    Path[1] = 1;
    Path[stage] = n - 1;
    for (int i = 2; i <= stage - 1; i++)
    {
        Path[i] = NextVertex[Path[i - 1]];
    }
    PrintMinCostPath(Path);
}
int main()
{ /* Multistages Graph: 
  
  *** Dp Approch: Dp Says that Take Dicision at each node(point) and pick up best option(here pick up min cost vertex). 
      Dp Follow Tabularation
      Dp go from min value to greater value(use min value for next greater value)
      Dp indirectly(can not generate each Whole tree) try out all option ,and pick up best one. 
 Q. Find Minimum cost Path in a given Graph? 
  stages(s) => 
   s1   s2   s3  s4
        2---->5
      /   \ // \        1) All edges are set in forward direction.         
     /    /\/   \       2) costs of edges= 1-2 = 2  5-8 = 6      
    /   /  /\    \                         1-3 = 1  6-8 = 4
   1-->3--/-->6-->8                        1-4 = 3  7-8 = 5
   \     /  /    /                         2-5 = 2
    \   / /     /                          2-6 = 3
     \ //      /                           3-5 = 6
      4------>7                            3-6 = 7
                                           4-5 = 6
                                           4-6 = 8
 Use data structure:
  1) Adjecency Matrix.
  2) for store min Cost of each vertex we need A Array(MinCost)
  3) for store next vertex use Array(NextVertex)
  3) for store min cost Path use Array( Path)
*/
    // 0 row and 0 column are not represent Graph it just for indexing of matrix.

    int Graph[n][n] = {

        {0, 1, 2, 3, 4, 5, 6, 7, 8},
        {1, 0, 2, 1, 3, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 2, 3, 0, 0},
        {3, 0, 0, 0, 0, 6, 7, 0, 0},
        {4, 0, 0, 0, 0, 6, 8, 0, 0},
        {5, 0, 0, 0, 0, 0, 0, 0, 6},
        {6, 0, 0, 0, 0, 0, 0, 0, 4},
        {7, 0, 0, 0, 0, 0, 0, 0, 5},
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    int MinCost[n] = {0};
    int NextVertex[n] = {0};
    int Path[n] = {0};

    MinPathInMultiStageGp(Graph, MinCost, NextVertex, Path);

    return 0;
}