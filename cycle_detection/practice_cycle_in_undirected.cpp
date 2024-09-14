#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> ad_list[N];
bool visited_node[N];
int parent_arr[N];
bool isCycle;

void dfs(int src)
{
    visited_node[src] = true;

    for (int child : ad_list[src])
    {
        if (visited_node[child] && parent_arr[src] != child)
        {
            isCycle = true;
        }

        if (!visited_node[child])
        {
            parent_arr[child] = src;
            dfs(child);
        }
    }
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
        ad_list[b].push_back(a);
    }

    memset(visited_node, false, sizeof(visited_node));
    memset(parent_arr, -1, sizeof(parent_arr));

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