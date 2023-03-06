/*
     Author : Mahedi-Hasan10
     Date : 06-03-2023
*/
#include <bits/stdc++.h>
using namespace std;
const int maxN = 100;
int main()
{
    int n, e;
    cin >> n >> e;
    int adjMatrix[n][n];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}