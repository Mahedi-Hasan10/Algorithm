/*
     Author : Mahedi-Hasan10
     Date : 03-04-2023
     Topic: Graph Coloring Algorithm
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1002;
vector<int> adj_list[N];
int visited[N];
int color[N];

bool dfs(int node)
{
    visited[node] = 1;
    for (auto adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            if (color[node] == 1)
                color[adj_node] = 2;
            else
                color[adj_node] = 1;
            bool is_bicolorable = dfs(adj_node);
            if (!is_bicolorable)
                return false;
        }
        else
        {
            if (color[node] == color[adj_node])
                return false;
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
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bool is_bycolorable = true;
    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] == 0)
        {
            color[i] = 1;
            bool ok = dfs(i);
            if (!ok)
            {
                is_bycolorable = false;
                break;
            }
        }
    }

    for (int i = 1; i <= nodes; i++)
    {
        if (!is_bycolorable)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            cout << color[i] << " ";
        }
    }
    cout << endl;
    return 0;
}

/*

5 3
1 2
1 3
4 5

(1)  (2)
1-----2
|
3(2)


(1) (2)
4--5
*/