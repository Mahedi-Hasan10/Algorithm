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
    vector<int> adjList[maxN];
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto j : adjList[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}