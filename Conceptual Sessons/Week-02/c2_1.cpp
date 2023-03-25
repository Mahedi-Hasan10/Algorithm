/*
     Author : Mahedi-Hasan10
     Date : 15-03-2023
     Topic: DFS
*/
#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1000;
vector<int> adj[MaxN];
bool visited[MaxN];

void dfs(int node)
{
    visited[node] = true;
    cout << node << " ";
    for (auto child : adj[node])
    {
        if (!visited[child])
            dfs(child);
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}