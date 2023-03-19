/*
     Author : Mahedi-Hasan10
     Date : 11-03-2023
     Topic: Graph Representation (Adjacency Matrix)



A---B
   / \
   C--D

Convert to a number matrix :

0---1
   / \
   2--3

0->1
1->0

1->2
2->1

2->3
3->2

1->3
3->1

Time Complexity = O(n^2)
Space Complexity = O(n^2)

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nodes = 4;                 // O(1)
    int Matrix[nodes][nodes] = {}; // O(n^2)

    // O(n^2)
    Matrix[0][1] = 1;
    Matrix[1][0] = 1;

    Matrix[1][2] = 1;
    Matrix[2][1] = 1;

    Matrix[2][3] = 1;
    Matrix[3][2] = 1;

    Matrix[1][3] = 1;
    Matrix[3][1] = 1;

    // O(n^2)
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}