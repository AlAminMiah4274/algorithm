#include <bits/stdc++.h>
using namespace std;

vector<int> ad_list[1005];
bool visited_node[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);

    visited_node[src] = true;

    while (!q.empty())
    {
        int parent_node = q.front();
        q.pop();


        cout << parent_node << endl;

        // for (int i = 0; i < ad_list[parent_node].size(); i++)
        // {
        //     cout << ad_list[parent_node][i] << " ";
        // }

        for (int connected : ad_list[parent_node])
        {
            // cout << connected << " ";

            if (!visited_node[connected])
            {
                q.push(connected);
                visited_node[connected] = true;
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

    int source;
    cin >> source;

    bfs(source);

    return 0;
}