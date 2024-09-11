#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> ad_list[N];
bool visited_node[N];

void dfs(int src)
{
    cout << src << " ";
    visited_node[src] = true;

    // for (int i = 0; i < ad_list[src].size(); i++)
    // {
    //     int child = ad_list[src][i];

    //     if (!visited_node[child])
    //     {
    //         dfs(child);
    //     }
    // }

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

    dfs(0);

    return 0;
}