#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> ad_list[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;

        ad_list[a].push_back(b);
        ad_list[b].push_back(a);
    }

    int node;
    cin >> node;

    vector<int> connected_nodes;
    for (int i = 0; i < ad_list[node].size(); i++)
    {
        connected_nodes.push_back(ad_list[node][i]);
    }

    cout << connected_nodes.size() << endl;

    return 0;
}