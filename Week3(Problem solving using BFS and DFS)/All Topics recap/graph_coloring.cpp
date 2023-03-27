/*
     Author : Mahedi-Hasan10
     Date : 27-03-2023
     Topic: Implement Graph Coloring Algorithm using DFS
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
vector<int> adjList[N];
int visited[N];
int color[N];

bool dfs(int node)
{
    visited[node] = 1;

    for (int adj_child : adjList[node])
    {
        if (visited[adj_child] == 0)
        {
            if (color[node] == 1)
                color[adj_child] = 2;
            else
                color[adj_child] = 1;
            bool is_bycolorable = dfs(adj_child);
            if (!is_bycolorable)
            {
                return false;
            }
        }
        else
        {
            if (color[node] == color[adj_child])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool is_bicolorable = true;
    for (int i = 1; i <= nodes; i++)
    {
        if (visited[i] == 0)
        {
            color[i] = 1;
            bool ok = dfs(i);
            if (!ok)
            {
                is_bicolorable = false;
                break;
            }
        }
    }

    if (!is_bicolorable)
        cout << "IMPOSSIBLE\n";
    else
    {
        for (int i = 1; i <= nodes; i++)
        {
            cout << color[i] << " ";
        }
        cout << endl;
    }

    return 0;
}