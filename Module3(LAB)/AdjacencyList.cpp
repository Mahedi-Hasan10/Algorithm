/*
     Author : Mahedi-Hasan10
     Date : 11-03-2023
     Topic: Graph Representation (Adjacency List)



A---B
   / \
   C--D

Convert to a number :

0---1
   / \
   2--3

0->1
1-> 2,3
2->1,3
3->1,2

Time Complexity = O(n^2)
Space Complexity = O(n^2)

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Adjacency list + Undirected +Unweighted
    //  int nodes = 4; // O(1)
    //  int adjList[nodes];

    // adjList[0] = {1};
    // adjList[1] = {2, 3};
    // adjList[2] = {1, 3};
    // adjList[3] = {1, 2};

    // for (int i = 0; i < nodes; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j = 0; j < adjList[i].size(); j++)
    //     {
    //         cout << adjList[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Using Directed + Weighted
    //  0->(1,2)
    //  1->(2,4)
    //  2->
    //  3->(2,8),(1,7)

    int nodes1 = 4;
    vector<pair<int, int>> adjList1[nodes1];

    adjList1[0].push_back({1, 2});
    adjList1[1].push_back({2, 4});
    adjList1[3].push_back({2, 8});
    adjList1[3].push_back({1, 7});

    for (int i = 0; i < nodes1; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjList1[i].size(); j++)
        {
            cout << "(" << adjList1[i][j].first << ", " << adjList1[i][j].second << " ),";
        }
        cout << endl;
    }

    return 0;
}