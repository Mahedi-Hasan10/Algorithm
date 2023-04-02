/*
     Author : Mahedi-Hasan10
     Date : 02-04-2023
     Topic: Single Source Shortest Path Algorithm
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2002;
vector<int> adjList[N];
int visited[N], level[N];

void bfs(int node)
{
    queue<int> q;
    visited[node] = 1;
    level[node] = 0;
    q.push(node);

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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "level -> " << i << "-->" << level[i] << "\n";
    }
    return 0;
}

/*
Input:
7 6
1 2
1 3
2 4
3 5
3 7
2 6

Output :

level -> 1-->0
level -> 2-->1
level -> 3-->1
level -> 4-->2
level -> 5-->2
level -> 6-->2
level -> 7-->2


*/