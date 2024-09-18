#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

class Edge
{
public:
    int from, to, cost;

    Edge(int from, int to, int cost)
    {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};

int distance_cost[N];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edge_list;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 0; i < n; i++)
    {
        distance_cost[i] = INT_MAX;
    }

    distance_cost[0] = 0;
    for (int i = 1; i <= n - 1; i++) // complexity: O(V * E) 
    {
        for (Edge e : edge_list)
        {
            // cout << e.from << " " << e.to << " " << e.cost << endl;
            int from_node, to_node, traversing_cost;
            from_node = e.from;
            to_node = e.to;
            traversing_cost = e.cost;

            if (distance_cost[from_node] < INT_MAX && distance_cost[from_node] + traversing_cost < distance_cost[to_node])
            {
                distance_cost[to_node] = distance_cost[from_node] + traversing_cost;
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        cout << i << " --> " << distance_cost[i] << endl;
    }

    return 0;
}