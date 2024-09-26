#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

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
        group_size[leader_b] += group_size[leader_a];
    }
}



int main()
{
    int n, e;
    cin >> n >> e;

    dsu_initialization(n);
    bool cycle = false;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leader_a = find_leader(a);
        int leader_b = find_leader(b);

        if (leader_a == leader_b)
        {
            cycle = true;
        }
        else 
        {
            union_by_size(a, b);
        }
    }

    if (cycle)
    {
        cout << "Cycle found" << endl;
    }
    else 
    {
        cout << "cycle not found" << endl;
    }

    return 0;
}