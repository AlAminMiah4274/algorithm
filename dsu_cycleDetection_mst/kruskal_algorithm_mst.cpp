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

bool cost_compare(Edge a, Edge b)
{
    return a.cost < b.cost;
}

int parent[N];
int group_size[N];
void dsu_initialization(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int find_leader(int node)
{
    if (parent[node] == -1) return node;
    int leader = find_leader(parent[node]);
    parent[node] = leader;
    return leader;
}

void union_by_size(int node1, int node2)
{
    int leader_a = find_leader(node1);
    int leader_b = find_leader(node2);

    if (group_size[leader_a] > group_size[leader_b])
    {
        parent[leader_b] = leader_a;
        group_size[leader_a] += group_size[leader_b];
    }
    else 
    {
        parent[leader_a] = leader_b;
        group_size[leader_b] = group_size[leader_a];
    }
}


int main()
{
    int n, e;
    cin >> n >> e;

    dsu_initialization(n);

    vector<Edge> ed_list;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        ed_list.push_back(Edge(a, b, c));
    }

    sort(ed_list.begin(), ed_list.end(), cost_compare);
    int total_cost = 0;
    for (Edge ed : ed_list)
    {
        // cout << ed.from << " " << ed.to << " " << ed.cost << endl;
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

    cout << total_cost << endl;



    return 0;
}