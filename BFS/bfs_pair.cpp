#include <bits/stdc++.h>
using namespace std;


vector<int> ad_list[1005];
bool visited_node[1005];

void bfs(int src, int destination)
{
    queue<pair<int, int>> ad_list_queue;
    ad_list_queue.push({src, 0});

    visited_node[src] = true;
    bool got_destination = false;

    while (!ad_list_queue.empty())
    {
        pair<int, int> parent_node = ad_list_queue.front();
        int index = parent_node.first;
        int level = parent_node.second;
        ad_list_queue.pop();

        if (index == destination)
        {
            cout << level << endl;
            got_destination = true;
        }

        for (int child : ad_list[index])
        {
            if (!visited_node[child])
            {
                ad_list_queue.push({child, level + 1});
                visited_node[child] = true;
            }
        }
    }

    if (!got_destination)
    {
        cout << "Not edged" << endl;
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

    int source;
    cin >> source;

    memset(visited_node, false, sizeof(visited_node));

    bfs(source, 8);


    return 0;
}