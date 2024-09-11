#include <bits/stdc++.h>
using namespace std;
const int V = 1e5 + 5;


vector<int> ad_list[V];
bool visited_node[V];


void dfs(int src)
{
    cout << src << " ";
    visited_node[src] = true;

    for (int child : ad_list[src])
    {
        if (!visited_node[child])
        {
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

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited_node[i])
        {
            dfs(i);
            count++;
        }
    }

    cout << endl;

    cout << "component: " << count << endl;

    return 0;
}