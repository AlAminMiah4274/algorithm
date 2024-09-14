#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> ad_list[N];
bool visited_node[N];
int parent_of_child[N];
bool isCycle;

void bfs(int src)
{
    queue<int> ad_list_queue;
    ad_list_queue.push(src);

    visited_node[src] = true;

    while (!ad_list_queue.empty())
    {
        /*
        there is cycle: visited node, parent of the immediate parent
        and child are not same

        input:
        7 6
        0 1
        1 2
        3 4
        4 5
        5 6
        6 3
        */
        int parent_node = ad_list_queue.front();
        ad_list_queue.pop();

        // cout << parent_node << endl;

        for (int child : ad_list[parent_node])
        {
            if (visited_node[child] && parent_of_child[parent_node] != child)
            {
                isCycle = true;
            }

            if (!visited_node[child])
            {
                ad_list_queue.push(child);
                visited_node[child] = true;
                parent_of_child[child] = parent_node;
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

    memset(visited_node, false, sizeof(visited_node));
    memset(parent_of_child, -1, sizeof(parent_of_child));

    isCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited_node[i])
        {
            bfs(i);
        }
    }

    if (isCycle)
    {
        cout << "Cycle found" << endl;
    }
    else
    {
        cout << "Cycle not found" << endl;
    }

    return 0;
}