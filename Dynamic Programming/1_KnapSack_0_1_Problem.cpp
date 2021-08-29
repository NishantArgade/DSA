#include <iostream>
using namespace std;

#define n 4
#define c 10

int mat[n][c];

void Knapsack_Problem(int cost[n], int weight[n])
{
    for (int i = 0; i < n + 1; i++)
        mat[i][0] = 0;
    for (int j = 0; j < c + 1; j++)
        mat[0][j] = 0;

    for (int item = 1; item <= n; item++)
    {
        for (int capa = 1; capa <= c; capa++)
        {
            int prevMaxCost = mat[item - 1][capa];
            int currCost = 0;
            int currWt = weight[item - 1];

            if (currWt <= capa)// Check weither Object aplicable for added or not if yes then change curr cost
            {
                currCost = cost[item - 1];
                int remainingCapa = capa - currWt;
                currCost += mat[item - 1][remainingCapa];
            }// if not then then set previous max value
            
            mat[item][capa] = max(prevMaxCost, currCost);
        }
    }
    cout << "\n\n Maximum cost with minimum weight is " << mat[n][c];
}
int main()
{    
    /*KnapSack Problem ( 0/1 method):
    Select  items /Objects form set of Objects such that total cost after taking element in a sack is maximun .
    and  with minimum weight(Total weight <= Capacity of Sack).

    //DP Approach:
    use 2D Array for memoization(store result)

    Approch:
    update all matrix with maximun cost and at the last mat[n][c] we get max value / cost.

   ** You can also solve using Set.
*/
    int cost[] = {20, 30, 10, 50};
    int weight[] = {1, 3, 4, 6};

    Knapsack_Problem(cost, weight);
    return 0;
}