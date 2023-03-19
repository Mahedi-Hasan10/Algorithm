/*
     Author : Mahedi-Hasan10
     Date : 17-03-2023
     Topic: DFS traversal in any graph or tree
*/
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000;
vector<int> adj_list[maxN];
int visited[maxN];

void dfs(int node)
{
    cout << node << " ";
    visited[node] = 1;
    for (int adj_child : adj_list[node])
    {
        if (visited[adj_child] == 0)
        {
            dfs(adj_child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1);
    return 0;
}
