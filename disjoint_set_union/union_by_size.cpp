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


void union_by_size(int node1, int node2) // complexity: O(a(n)) 
{
    int leader_A = find_leader(node1);
    int leader_B = find_leader(node2);

    if (group_size[leader_A] > group_size[leader_B])
    {
        parent[leader_B] = leader_A;
        group_size[leader_A] += group_size[leader_B];
    }
    else 
    {
        parent[leader_A] = leader_B;
        group_size[leader_B] += group_size[leader_A];
    }
}



int main()
{
    dsu_initialization(7);

    union_by_size(1, 2);
    union_by_size(2, 3);
    union_by_size(4, 5);
    union_by_size(5, 6);

    union_by_size(1, 4);

    cout << find_leader(1) << endl;
    cout << find_leader(4) << endl;
    

    return 0;
}