#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> ad_list[N];
bool visited_node[N];


int dfs(int src)
{
    visited_node[src] = true;

    int count = 0;
    for (int child : ad_list[src])
    {
        if (!visited_node[child])
        {
            int num = dfs(child);
            count += num;
        }
    }

    return count + 1;
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

    vector<int> nodes_count;
    for (int i = 0; i < n; i++)
    {
        if (!visited_node[i])
        {
            int node = dfs(i);
            nodes_count.push_back(node);
        }
    }

    sort(nodes_count.begin(), nodes_count.end());
    for (int n : nodes_count)
    {
        cout << n << " ";
    }

    return 0;
}