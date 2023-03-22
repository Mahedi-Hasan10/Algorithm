/*
     Author : Mahedi-Hasan10
     Date : 22-03-2023
     Topic: DFS traversal in any graph or tree
*/
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000;
vector<int> adj_list[maxN];
int visited[maxN];
int color[maxN];

bool dfs(int node)
{
    visited[node] = 1;

    for (int adj_child : adj_list[node])
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
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool is_bicolorable = true;
    for (int i = 1; i <= n; i++)
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
        for (int i = 1; i <= n; i++)
        {
            cout << color[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
