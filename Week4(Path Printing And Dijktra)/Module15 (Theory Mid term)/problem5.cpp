/*
     Author : Mahedi-Hasan10
     Date : 01-04-2023
     Topic: Bangladesh has n cities, and m roads between them.
     You can go from one city to another if there exists a path between those two cities.
     The goal is to  reach from city 1 to n.

*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N];

void bfs(int src)
{
    queue<int> q;
    visited[src] = 1;
    q.push(src);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (auto adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
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
    bfs(1);

    if (visited[nodes] == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}