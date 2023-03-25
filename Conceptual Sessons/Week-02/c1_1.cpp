/*
     Author : Mahedi-Hasan10
     Date : 15-03-2023
     Topic: BFS
*/
#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1000;
vector<int> adj[MaxN];
bool visited[MaxN];
void bfs(int s)
{
    queue<int> q;
    cout << s << " ";
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : adj[node])
        {
            if (!visited[child])
            {
                visited[child] = true;
                q.push(child);
                cout << child << " ";
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << i << "-> ";
    //     for (auto child : adj[i])
    //     {
    //         cout << child << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}

/*

10 8
1 2
1 3
2 3
3 4
3 5
4 5
5 6
6 7

*/