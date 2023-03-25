/*
     Author : Mahedi-Hasan10
     Date : 25-03-2023
     Topic:Check if a graph is Bipartite or not
*/

/*
bicolorable and bipartite graph are the same thing.
A graph is said to be "bipartite" if and only if it is "bicolorable".
so we can solve the problem after checking bycolorable or not. if it bycolorable
then its a bipertite graph otherwise itsnot bipertite graph.

*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2002;
vector<int> adj_list[N];
int visited[N];
int color[N];

bool dfs(int node)
{
    visited[node] = 1;
    for (int adj_child : adj_list[node])
    {
        if (visited[adj_child] == 0)
        {
            if (color[node] == 1)
            {
                color[adj_child] = 2;
            }
            else
            {
                color[adj_child] = 1;
            }

            bool is_bicolorable = dfs(adj_child);
            if (!is_bicolorable)
                return false;
        }
        else
        {
            if (color[node] == color[adj_child])
                return false;
        }
    }
    return true;
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

    bool is_bycolorable = true;

    for (int i = 0; i <= nodes; i++)
    {
        if (visited[i] == 0)
        {
            color[i] = 1;
            bool ok = dfs(i);
            if (!ok)
            {
                is_bycolorable = false;
                break;
            }
        }
    }

    if (!is_bycolorable)
        cout << "NOT Byperite\n";
    else
        cout << "Bypertite\n";
    return 0;
}