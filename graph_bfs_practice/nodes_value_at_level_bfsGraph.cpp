#include <bits/stdc++.h>
using namespace std;

vector<int> ad_list[1005];
bool visited_node[1005];

void bfs(int src, int lev)
{
    queue<pair<int, int>> ad_list_queue;
    ad_list_queue.push({src, 0});

    visited_node[src] = true;
    vector<int> level_nodes;

    while (!ad_list_queue.empty())
    {
        pair<int, int> parent_node = ad_list_queue.front();
        int node_value = parent_node.first;
        int level = parent_node.second;
        ad_list_queue.pop();

        if (level == lev)
        {
            level_nodes.push_back(node_value);
        }

        for (int child : ad_list[node_value])
        {
            if (!visited_node[child])
            {
                ad_list_queue.push({child, level + 1});
                visited_node[child] = true;
            }
        }
    }

    reverse(level_nodes.begin(), level_nodes.end());
    for (int node : level_nodes)
    {
        cout << node << " ";
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

    int required_level;
    cin >> required_level;

    memset(visited_node, false, sizeof(visited_node));

    bfs(0, required_level);

    

    return 0;
}