#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<pair<int, int>> ad_list[N];
int distance_cost[N];


void dijkstra(int src) // complexity: O(V * E)/ O(N * E) 
{
    queue<pair<int, int>> ad_list_queue;
    ad_list_queue.push({});

    distance_cost[src] = 0;

    while (!ad_list_queue.empty())
    {
        pair<int, int> parent = ad_list_queue.front();
        int node = parent.first;
        int cost = parent.second;
        ad_list_queue.pop();

        // for (int i = 0; i < ad_list[node].size(); i++)
        // {
        //     pair<int, int> child = ad_list[node][i];
        // }

        for (pair<int, int> child : ad_list[node])
        {
            int child_node = child.first;
            int child_cost = child.second;

            if (cost + child_cost < distance_cost[child_node])
            {
                // path relax 
                distance_cost[child_node] = cost + child_cost;
                ad_list_queue.push({child_node, distance_cost[child_node]});

                /*
                ad_list_queue.push({child_node, cost + child_cost});
                distance_cost[child_node] = cost + child_cost;
                */
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
        int a, b, c;
        cin >> a >> b >> c;

        ad_list[a].push_back({b, c});
        ad_list[b].push_back({a, c});
    }

    // memset(distance_cost, INT_MAX, sizeof(distance_cost));

    for (int i = 0; i < n; i++)
    {
        distance_cost[i] = INT_MAX;
    }

    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << " --> " << distance_cost[i] << endl;
    }


    return 0;
}