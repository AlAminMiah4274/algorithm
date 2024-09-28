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


int parent[N];
int group_size[N];
void dsu_initialization(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}


int find_leader(int node)
{
    if (parent[node] == -1) return node;
    int leader = find_leader(parent[node]);
    parent[node] = find_leader(parent[node]);
    return leader;
}


void union_by_size(int node1, int node2)
{
    int leader_node1 = find_leader(node1);
    int leader_node2 = find_leader(node2);

    if (group_size[leader_node1] > group_size[leader_node2])
    {
        parent[leader_node2] = leader_node1;
        group_size[leader_node1] += group_size[leader_node2];
    }
    else 
    {
        parent[leader_node1] = leader_node2;
        group_size[leader_node2] += group_size[leader_node1];
    }
}

bool cost_compare(Edge a, Edge b)
{
    return a.cost < b.cost;
}




int main()
{
    int n, e;
    cin >> n >> e;

    dsu_initialization(n);
    long long int total_cost = 0;
    vector<Edge> ed_list;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        ed_list.push_back(Edge(a, b, c));
    }


    sort(ed_list.begin(), ed_list.end(), cost_compare);
    for (Edge ed : ed_list)
    {
        int leader_from = find_leader(ed.from);
        int leader_to = find_leader(ed.to);

        if (leader_from == leader_to)
        {
            continue;
        }
        else 
        {
            union_by_size(ed.from, ed.to);
            total_cost += ed.cost;
        }
    }

    // cout << total_cost << endl;

    int leader_all_nodes = find_leader(1);
    bool connected_all_nodes = true;
    for (int i = 1; i <= n; i++)
    {
        if (find_leader(i) != leader_all_nodes)
        {
            connected_all_nodes = false;
        }
    }

    if (connected_all_nodes) cout << total_cost << endl;
    else cout << "IMPOSSIBLE" << endl;


    return 0;
}