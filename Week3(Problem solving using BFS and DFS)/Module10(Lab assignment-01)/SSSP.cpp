/*
     Author : Mahedi-Hasan10
     Date : 24-03-2023
     Topic: The single source shortest path(SSSP) problem using BFS
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
        for (auto adjNode : adjList[head])
        {
            if (visited[adjNode] == 0)
            {
                visited[adjNode] = 1;
                level[adjNode] = level[head] + 1;
                q.push(adjNode);
            }
        }
    }
}
int main()
{
    adjList[0] = {1, 3, 4};
    adjList[1] = {0, 2, 5};
    adjList[2] = {1, 4};
    adjList[3] = {0};
    adjList[4] = {2, 5};
    adjList[5] = {1, 4};
    bfs(0);

    for (int i = 0; i <= 5; i++)
    {
        cout << "node " << i << " -> Level: " << level[i] << "\n";
    }

    return 0;
}

/*
input :
5 7

0 1
0 3
0 4
1 2
1 5
2 4
4 5

node 0 -> Level: 0
node 1 -> Level: 1
node 2 -> Level: 2
node 3 -> Level: 1
node 4 -> Level: 1
node 5 -> Level: 2
*/