/*
     Author : Mahedi-Hasan10
     Date : 24-03-2023
     Topic: Convert Adjacency Matrix to An Adjacency List
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int adjMatrix[N][N];

    // Take input of Adjacency Matrix :
    vector<int> adjList[N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    // Convert the adjacency matrix to adjacency list
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }

    // Print the adjacency List
    for (int i = 0; i < N; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}