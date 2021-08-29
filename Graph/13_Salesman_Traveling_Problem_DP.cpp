#include <iostream>
#include <limits.h>
using namespace std;

#define VISITED_ALL (1 << n) - 1
#define n 4

int GetMinCostpath(int Dist[n][n], int mask, int pos)
{
    if (mask == VISITED_ALL)
        return Dist[pos][0];

int ans = INT_MAX;

    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0000)
        {
            int newAns = Dist[pos][city] + GetMinCostpath(Dist,mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return ans;
}
int main()
{ /* Minimum Dist of Hamiltonian cycle .

problem: Find A path(way) for salesman travelling in the city such that travelling cost be minimum.
Real life use:
In Google map
in Ubber ,online parsal servise etc..

  Non Directed Graph:
   (1)-----(2)
    | \    /|
    |  \ /  |
    |  / \  |
    |/    \ |
   (4)-----(3)

    Cites  Binary bit
    1    =>   0001
    2    =>   0010
    3    =>   0011
    4    =>   0100

Time complexcity=> )=O(n^2)
  if ALl Are Visited mark as 1111
*/
    int Graph[n][n] = {{0, 10, 15, 20},
                       {5, 0, 9, 10},
                       {6, 13, 0, 12},
                       {8, 8, 9, 0}};

cout<<"Minimun Cost way for salesman travelling in city is "<<GetMinCostpath(Graph,1,0);

    return 0;
}