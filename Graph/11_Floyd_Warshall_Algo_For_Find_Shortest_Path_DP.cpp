#include <iostream>
#include <limits.h>
using namespace std;

#define I 999999
#define V 4
#define n 5


void printSol(int dist[n][n])
{
    cout<<"Shortest Path Matrix"<<endl;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {

            if (dist[i][j] == I)
                cout << " I ";
            else
                cout <<" "<< dist[i][j] <<" ";
        }
        cout << endl;
    }
}
void ShortestPath(int Graph[n][n])
{
    int dist[n][n]={0};
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
            dist[i][j] = Graph[i][j];
        }

    //Reapet (V) vertices Times
    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V && (i != k); i++)
        {
            for (int j = 1; j <= V && (j != k); j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    // print Solution :
    printSol(dist);
}
int main()
{
    /* Floyd Warshall Algorethem for find shortest path with only positive cost:
                          (1-2 cost: 8,2-1 cost:3) 
                     (1)<--- ->(2)
                      | ^      | 
 1->4(cost:7)----->  |   \    |2 
 4->1(cost:2)-----> |     \  |
                   |       \|  <------------ 2 to 3
                 (4)<-----(3)
                      1

       TC= O(n^2) 
*/
    //      1  2  3  4
    int Graph[n][n] = {
        {I, I, I, I, I},

        {I, 0, 3, I, 7}, //1
        {I, 8, 0, 2, I}, //2
        {I, 5, I, 0, 1}, //3
        {I, 2, I, I, 0}  //4

    };
    ShortestPath(Graph);

    return I;
}