/*
     Author : Mahedi-Hasan10
     Date : 28-03-2023
     Topic: Printing the path from e source node to a destination node
     problem : https://cses.fi/problemset/task/1667
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 * 5;
vector<int> adj_list[N];
int visited[N], level[N], parent[N];

void bfs(int src)
{
    visited[src] = 1;
    level[src] = 1;
    parent[src] = -1;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                parent[adj_node] = head;
                q.push(adj_node);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 1;
    int dst_node = n;
    bfs(1);
    if (visited[dst_node] == 0)
    {
        cout << "IMPOSSIBLE\n";
    }

    cout << level[dst_node] << "\n";
    int selected_node = dst_node;
    vector<int> path;
    while (true)
    {
        path.push_back(selected_node);
        if (selected_node == src)
        {
            break;
        }
        selected_node = parent[selected_node];
    }

    reverse(path.begin(), path.end());
    for (int node : path)
    {
        cout << node << " ";
    }
    cout << "\n";
    return 0;
}