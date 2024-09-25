#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;


int parent[N];
int level[N];
void dsu_initialization(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        level[i] = 0;
    }
}


int find_leader(int node)
{
    if (parent[node] == -1) return node;
    int leader = find_leader(parent[node]);
    parent[node] = leader;
    return leader;
}


void union_by_level(int node1, int node2) // complexity: O(a(n)) 
{
    int leader_a = find_leader(node1);
    int leader_b = find_leader(node2);

    if (level[leader_a] > level[leader_b])
    {
        parent[leader_b] = leader_a;
    }
    else if (level[leader_a] < level[leader_b])
    {
        parent[leader_a] = leader_b;
    }
    else 
    {
        parent[leader_a] = leader_b;
        level[leader_b]++;
    }
}


int main()
{
    dsu_initialization(7);

    union_by_level(1, 2);
    union_by_level(2, 3);
    union_by_level(4, 5);
    union_by_level(5, 6);
    union_by_level(1, 4);

    cout << find_leader(1) << endl;
    cout << find_leader(4) << endl;

    return 0;
}