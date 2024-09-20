#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 5;
const long long int INF = 1e18 + 5;

class Edge
{
public:
    ll src_node, des_node, cost;
    
    Edge(ll src_node, ll des_node ,ll cost)
    {
        this->src_node = src_node;
        this->des_node = des_node;
        this->cost = cost;
    }
};

ll distance_cost[N];

int main()
{
    // Write your code here
    
    int node, edge;
    cin >> node >> edge;
    
    vector<Edge> edge_list;
    while (edge--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        
        edge_list.push_back(Edge(a, b, w));
    }
    
    int source;
    cin >> source;
    
    int q;
    cin >> q;
    
    for (int i = 1; i <= node; i++)
    {
        distance_cost[i] = INF;
    }
    
    distance_cost[source] = 0;
    
//     to find the shortest path of minimum cost 
    for (int i = 1; i < node - 1; i++)
    {
        for (Edge e : edge_list)
        {
            ll from, to, visiting_cost;
            from = e.src_node;
            to = e.des_node;
            visiting_cost = e.cost;
            
            if (distance_cost[from] < INF && distance_cost[from] + visiting_cost < distance_cost[to])
            {
                distance_cost[to] = distance_cost[from] + visiting_cost;
            }
        }
    }
    
    bool cycle = false;
    for (Edge e : edge_list)
    {
        long long from, to, visiting_cost;
        from = e.src_node;
        to = e.des_node;
        visiting_cost = e.cost;
            
        if (distance_cost[from] < INF && distance_cost[from] + visiting_cost < distance_cost[to])
        {
            cycle = true;
            break;
        }
    }
    
    // for (int i = 1; i <= node; i++)
    // {
    //     cout << i << " --> " << distance_cost[i] << endl;
    // }
    
    while (q--)
    {
        int d;
        cin >> d;
        
        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else if (distance_cost[d] >= INF)
        {
            cout << "Not Possible" << endl;
        }
        else 
        {
            cout << distance_cost[d] << endl;
        }
    }
    

    return 0;
}