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

    for (int i = 1; i < n - 1; i++)
    {
        for (Edge e : edge_list)
        {
            int from_node, to_node, visiting_cost;
            from_node = e.from;
            to_node = e.to;
            visiting_cost = e.cost;

            if (distance_cost[from_node] < INT_MAX && distance_cost[from_node] + visiting_cost < distance_cost[to_node])
            {
                distance_cost[to_node] = distance_cost[from_node] + visiting_cost;
            }
        }
    }

    bool cycle = false;
    for (Edge e : edge_list)
    {
        int from_node, to_node, visiting_cost;
        from_node = e.from;
        to_node = e.to;
        visiting_cost = e.cost;

        if (distance_cost[from_node] < INT_MAX && distance_cost[from_node] + visiting_cost < distance_cost[to_node])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Cycle found. No answer" << endl;
    }
    else 
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " --> " << distance_cost[i] << endl;
        }
    }



    return 0;
}

/*
Detected cycle in directed graph. Basically bellman ford algorithm is used in 
negative weighted directed or undirected graph in which has cycle. 
*/