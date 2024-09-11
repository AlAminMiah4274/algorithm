#include <bits/stdc++.h>
using namespace std;

vector<int> ad_list[1005];
bool visited_node[1005];

void bfs(int src, int des)
{
    queue<pair<int, int>> ad_list_queue;
    ad_list_queue.push({src, 0});

    visited_node[src] = true;
    bool connected = false;

    while (!ad_list_queue.empty())
    {
        pair<int, int> parent_node = ad_list_queue.front();
        int parent_value = parent_node.first;
        int level = parent_node.second;
        ad_list_queue.pop();

        if (des == parent_value)
        {
            cout << level << endl;
            connected = true;
        }

        for (int child : ad_list[parent_value])
        {
            if (!visited_node[child])
            {
                ad_list_queue.push({child, level + 1});
                visited_node[child] = true;
            }
        }
    }

    if (!connected)
    {
        cout << "-1" << endl;
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

    int q;
    cin >> q;

    while (q--)
    {
        int source, destination;
        cin >> source >> destination;

        memset(visited_node, false, sizeof(visited_node));

        bfs(source, destination);
    }

    return 0;
}