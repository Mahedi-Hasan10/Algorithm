/*
     Author : Mahedi-Hasan10
     Date : 25-03-2023
     Topic: Count the number of connected components
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2002;
vector<int> adj_list[N];
int visited[N];

int bfs(vector<int> adjList[], int nodes)
{

    int count = 0;
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            count++;
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while (!q.empty())
            {
                int head = q.front();
                q.pop();
                for (int adj_child : adjList[head])
                {
                    if (!visited[adj_child])
                    {
                        visited[adj_child] = 1;
                        q.push(adj_child);
                    }
                }
            }
        }
    }
    return count;
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

    int count = bfs(adj_list, nodes);
    cout << count << "\n";

    return 0;
}