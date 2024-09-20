#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 5;

vector<pair<int, int>> ad_list[N];
ll distance_cost[N];


class Compare
{
 public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        return a.second > b.second;
    }
};

void cost_counting(int src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> ad_list_queue;
    ad_list_queue.push({src, 0});
    
    distance_cost[src] = 0;
    
    while (!ad_list_queue.empty())
    {
        pair<ll, ll> parent = ad_list_queue.top();
        ll node = parent.first;
        ll cost = parent.second;
        ad_list_queue.pop();
        
        for (pair<ll, ll> child : ad_list[node])
        {
            ll child_node = child.first;
            ll child_cost = child.second;
            
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
    // Write your code here
    int node, edge;
    cin >> node >> edge;
    
    while (edge--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        
        ad_list[a].push_back({b, w});
    }
    
    int source;
    cin >> source;
    
    int q;
    cin >> q;
    
    for (int i = 1; i <= node; i++)
    {
        distance_cost[i] = INT_MAX;
    }
    
    cost_counting(source);
    
    while (q--)
    {
        ll d, dw;
        cin >> d >> dw;
        
        if (distance_cost[d] <= dw)
        {
            cout << "YES" << endl;
        }
        else 
        {
            cout << "NO" << endl;
        }
    }
    
    // for (int i = 1; i <= node; i++)
    // {
    //     cout << i << " --> " << distance_cost[i] << endl;
    // }
    

    return 0;
}
