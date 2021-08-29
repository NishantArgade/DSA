#include <iostream>
#include <limits.h>
using namespace std;

#define I INT_MAX
#define V 6
#define E 8
#define n 7

void BellmanFordAlgo(int Graph[n][n], int start)
{
    int Dis[n];
    int parent[n];
    bool update;

    for (int i = 0; i < n; i++)
    {
        Dis[i] = I;
        parent[i] = -1;
    }
    Dis[start] = 0;
    parent[start] = start;

    //Reapet up to V times( t <= V )
    for (int t = 1; t <= V; t++)
    {
        update = false;

        // For each vertex(v) ,do relaxe its adjecent
        for (int v = 1; v <= V; v++)
        {
            for (int j = 1; j <= V; j++) // Adjecent
            {
                if (Graph[v][j] != 0)
                {
                    int adj = j;
                    if (Dis[v] + Graph[v][adj] < Dis[adj]) // relax( Update)
                    {
                        Dis[adj] = Dis[v] + Graph[v][adj];
                        parent[adj] = v;
                        update = true;
                    }
                }
            }
        }
        // till up to V-1 time( t == V-1),there will be some update in each time(t)
        //But Afterward V-1 --> V : if any update is happen =>then Negative edge cycle(sum of all edges cost is -ve and form cycle).
        // Otherwise No Negative Age cycle exists.
        if (t == V && update == true)
        {
            cout << "\n\nThe Graph Has Negative edge Cycle !";
            return;
        }
        else if (update == false)
            break;
    }

    // print Distance And Shortest way path.
    cout<<"\nBellman ford Algorethem for find shortest path with positive or negative cost is : \n"<<endl;
    for (int v = 1; v <= V; v++)
    {
        cout << "The Shortest Distance up to " << v << " through path " << parent[v] << " is " << Dis[v] << endl;
    }
}
int main()
{
    /* Bellman ford Algorethem for find shortest path with negative cost:
                             7
                        (2)------>(4)
    1->2----------> -2 / |        ^ \ 1  <----------- 4 to 6
                   (1)  1|<- 2-3 |-2(6)
    1->3--------->   4\ |        | / 5  <------------ 5 to 6
                      (3)----->(5)
                          3

    *Use Data Structure* :
    
    distance[7]={I , 0 , I , I , I , I , I }    
                 0   1   2   3   4   5   6  
    
    parent[7]={-1 , -1 , -1 , -1 , -1 ,-1 }    
               0   1   2   3   4   5   6  
    
   int visited= false/true

   Logic:

   relax all vertices v-1 time (TC: (V-1)(e)= n*n= n^2 SC: O(n))
   if After that update is not posible then we get shortest path
   if after that update is posible then there may have negative age cycle.

   relaxing a vertex:
   if(dis[1] + C(1,2) < dis[2])
       dis[2]= dis[1]+ c(1,2)

*/
    //      1  2  3  4  5  6
    int Graph[n][n] = {
        {0, 0, 0, 0, 0, 0, 0},

        {0, 0, -2, 4, 0, 0, 0}, //1
        {0, 0, 0, 1, 7, 0, 0}, //2
        {0, 4, 0, 0, 0, 3, 0}, //3
        {0, 0, 0, 0, 0, 0, 1},  //4
        {0, 0, 0, 0, -2, 0, 5}, //5
        {0, 0, 0, 0, 0, 0, 0}   //6

    };
    BellmanFordAlgo(Graph, 1);

    return 0;
}