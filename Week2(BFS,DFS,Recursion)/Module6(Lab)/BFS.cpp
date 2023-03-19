/*
     Author : Mahedi-Hasan10
     Date : 17-03-2023
     Topic:
*/
#include <bits/stdc++.h>
using namespace std;
int const maxN = 1000;
vector<int> adjList[maxN];
int visited[maxN];

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
        for (int adjnode : adjList[head])
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
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bfs(1);
    return 0;
}

/**
 *
6 6
1 2
1 5
2 3
2 4
4 5
3 6
*/