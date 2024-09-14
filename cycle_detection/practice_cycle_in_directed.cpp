#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> ad_list[N];
bool visited_node[N];
bool visited_path[N];
bool isCycle;


void dfs(int src)
{
    visited_node[src] = true;
    visited_path[src] = true;

    for (int child : ad_list[src])
    {
        if (visited_path[child])
        {
            isCycle = true;
        }

        if (!visited_node[child])
        {
            dfs(child);
        }
    }

    visited_path[src] = false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        ad_list[a].push_back(b);
    }

    memset(visited_node, false, sizeof(visited_node));
    memset(visited_path, false, sizeof(visited_path));

    isCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited_node[i])
        {
            dfs(i);
        }
    }

    if (isCycle)
    {
        cout << "true" << endl;
    }
    else 
    {
        cout << "false" << endl;
    }

    return 0;
}