#include <bits/stdc++.h>
using namespace std;


vector<int> ad_list[1005];
bool visited_node[1005];
int shortest_path_parent[1005];

void bfs(int src, int destination)
{
    queue<pair<int, int>> ad_list_queue;
    ad_list_queue.push({src, 0});

    visited_node[src] = true;

    while (!ad_list_queue.empty())
    {
        pair<int, int> parent_node = ad_list_queue.front();
        int parent = parent_node.first;
        int level = parent_node.second;
        ad_list_queue.pop();

        for (int child : ad_list[parent])
        {
            if(!visited_node[child])
            {
                ad_list_queue.push({child, level + 1});
                visited_node[child] = true;
                shortest_path_parent[child] = parent;
            }
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

    int source, location;
    cin >> source >> location;

    memset(visited_node, false, sizeof(visited_node));
    memset(shortest_path_parent, -1, sizeof(shortest_path_parent));

    bfs(source, location);

    int x = location;
    vector<int> shortest_path;

    while (x != -1)
    {
        // cout << x << " ";
        shortest_path.push_back(x);
        x = shortest_path_parent[x];
    }

    reverse(shortest_path.begin(), shortest_path.end());

    for (int path : shortest_path)
    {
        cout << path << " ";
    }

    return 0;
}