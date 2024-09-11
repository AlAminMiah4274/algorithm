#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> ad_list[N];
bool visited_node[N];
vector<int> node_numbers;

void dfs(int src)
{
    node_numbers.push_back(src);
    visited_node[src] = true;

    for (int child : ad_list[src])
    {
        if (!visited_node[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        ad_list[a].push_back(b);
        ad_list[b].push_back(a);
    }

    int source;
    cin >> source;

    memset(visited_node, false, sizeof(visited_node));

    dfs(source);

    cout << node_numbers.size() << endl;

    return 0;
}