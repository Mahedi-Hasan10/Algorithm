/*
     Author : Mahedi-Hasan10
     Date : 01-04-2023
     Topic: Cycle Detection in unweighted graph
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> adj_list[N];
int visited[N];
int parent[N];

bool detect_cycle(int node)
{
    visited[node] = true;
    for (auto adj_node : adj_list[node])
    {
        if (!visited[adj_node])
        {
            parent[adj_node] = node;
            if (detect_cycle(adj_node))
                return true;
        }
        else if (adj_node != parent[node])
            return true;
    }
    return false;
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
    if (detect_cycle(src))
        cout << "Cycle Exist" << endl;
    else
        cout << "No Cycle" << endl;
    return 0;
}