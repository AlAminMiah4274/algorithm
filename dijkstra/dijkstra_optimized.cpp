#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<pair<int, int>> ad_list[N];
int distance_cost[N];

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second > b.second)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};

void dijkstra(int src) // complexity: O((V + E) log V) 
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> ad_list_queue;
    ad_list_queue.push({src, 0});

    distance_cost[src] = 0;

    while (!ad_list_queue.empty())
    {
        pair<int, int> parent = ad_list_queue.top();
        int node = parent.first;
        int cost = parent.second;
        ad_list_queue.pop();

        for (pair<int, int> child : ad_list[node])
        {
            int child_node = child.first;
            int child_cost = child.second;

            if (cost + child_cost < distance_cost[child_node])
            {
                distance_cost[child_node] = cost + child_cost;
                ad_list_queue.push({child_node, distance_cost[child_node]});
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