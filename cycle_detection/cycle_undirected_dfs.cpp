#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> ad_list[N];
bool visited_node[N];
int parent_of_child[N];
bool isCycle;

void dfs(int src)
{
    visited_node[src] = true;

    for (int child : ad_list[src])
    {
        if (visited_node[child] && parent_of_child[src] != child)
        {
            isCycle = true;
        }

        if (!visited_node[child])
        {
            parent_of_child[child] = src;
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        ad_list[a].push_back(b);
        ad_list[b].push_back(a);
    }

    memset(visited_node, false, sizeof(visited_node));
    memset(parent_of_child, -1, sizeof(parent_of_child));

    isCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited_node[i])
        {
            dfs(i);
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << parent_of_child[i] << endl;
    // }

    if (isCycle)
    {
        cout << "Cycle found" << endl;
    }
    else 
    {
        cout << "Cycle not found" << endl;
    }

    return 0;
}