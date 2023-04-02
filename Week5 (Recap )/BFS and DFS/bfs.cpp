/*
     Author : Mahedi-Hasan10
     Date : 01-04-2023
     Topic: BFS Simulatin

     simulate : 1. Select a node
                2. Visit all the adjacent node of the selected node
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
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
        cout << head << " ";
        for (int adjnode : adj_list[head])
        {
            if (visited[adjnode] == 0)
            {
                visited[adjnode] = 1;
                q.push(adjnode);
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

    bfs(2);
    return 0;
}