#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

bool visited_node[N];
int parent[N];
vector<int> ad_list[N];


void bfs(int src)
{
    visited_node[src] = true;
    parent[src] = src;

    queue<int> ad_queue;
    ad_queue.push(src);

    while (!ad_queue.empty())
    {
        int parent_node = ad_queue.front();
        ad_queue.pop();

        for (int child : ad_list[src])
        {
            if (!visited_node[child])
            {
                ad_queue.push(child);
                visited_node[child] = true;
                parent[child] = parent_node;
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
    memset(parent, -1, sizeof(parent));


    bfs(1);

    vector<int> path;
    int par = 4;

    while (par != 0)
    {
        path.push_back(par);
        par = parent[par];
    }

    reverse(path.begin(), path.end());

    for (auto e : path)
    {
        cout << e << endl;
    }


    return 0;
}

// shortest path manipulation 