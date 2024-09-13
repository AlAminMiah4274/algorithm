#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> ad_list[N];
bool visited_node[N];
int child_parent[N];
bool isCycle;


void bfs(int src)
{
    queue<int> ad_list_queue;
    ad_list_queue.push(src);

    visited_node[src] = true;

    while (!ad_list_queue.empty())
    {
        /*
        there is cycle: visited node, parent and child of the node are not same 
        */
        int parent_node = ad_list_queue.front();
        ad_list_queue.pop();

        // cout << parent_node << endl;

        for (int child : ad_list[parent_node])
        {
            if (visited_node[child] && child_parent[parent_node] != child)
            {
                isCycle = true; 
            }

            if (!visited_node[child])
            {
                ad_list_queue.push(child);
                visited_node[child] = true;
                child_parent[child] = parent_node;
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
    memset(child_parent, -1, sizeof(child_parent));

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