/*
     Author : Mahedi-Hasan10
     Date : 19-03-2023
     Topic: Single Source Shortest Path using BFS
*/
#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1000;
vector<int> adj_list[MaxN];

int visited[MaxN];
int level[MaxN];

void bfs(int source)
{
    queue<int> q;
    visited[source] = 1;
    level[source] = 0;
    q.push(source);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (auto adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
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
    for (int i = 0; i <= nodes; i++)
    {
        cout << "Nodes-->" << i << "  level --> " << level[i] << "\n";
    }
    return 0;
}

/*

8 6

1 2
1 3
2 4
4 5
4 6
5 7

*/