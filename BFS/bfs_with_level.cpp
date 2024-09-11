#include <bits/stdc++.h>
using namespace std;

vector<int> ad_list[1005];
bool visited_node[1005];
int level[1005];

void bfs(int src)
{
    queue<int> ad_list_queue;
    ad_list_queue.push(src);

    visited_node[src] = true;
    level[src] = 0;

    while (!ad_list_queue.empty())
    {
        int parent_node = ad_list_queue.front();
        ad_list_queue.pop();

        // cout << parent_node << endl;

        for (int child : ad_list[parent_node])
        {
            // cout << child << " ";

            if (!visited_node[child])
            {
                ad_list_queue.push(child);
                visited_node[child] = true;
                level[child] = level[parent_node] + 1;
            }
        }
        // cout << endl;
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
    memset(level, -1, sizeof(level));

    bfs(source);

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << level[i] << endl;
    }

    return 0;
}