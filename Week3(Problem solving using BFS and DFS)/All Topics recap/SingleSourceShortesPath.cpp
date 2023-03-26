/*
     Author : Mahedi-Hasan10
     Date : 25-03-2023
     Topic: Single Source Shortest Path
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<int> adjList[N];
int visited[N];
int level[N];

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
        for (auto adjChild : adjList[head])
        {
            if (!visited[adjChild])
            {
                visited[adjChild] = 1;
                level[adjChild] = level[head] + 1;
                q.push(adjChild);
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

    for (int i = 1; i <= e; i++)
    {
        cout << "Nodes " << i << " level-> " << level[i] << "\n";
    }
    return 0;
}