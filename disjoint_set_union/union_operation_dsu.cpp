#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int parent[N];
void dsu_initialization(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }

    parent[1] = 2;
    parent[2] = 3;
    parent[5] = 6;
    parent[6] = 7;
}

int find_leader(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = find_leader(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader_a = find_leader(node1);
    int leader_b = find_leader(node2);
    parent[leader_a] = leader_b;
}

int main()
{
    dsu_initialization(8);

    cout << find_leader(1) << endl;
    dsu_union(1, 5);
    cout << find_leader(1) << endl;

    return 0;
}