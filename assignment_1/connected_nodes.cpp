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

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;


        vector<int> connected_nodes;
        for (int child : ad_list[x])
        {
            connected_nodes.push_back(child);
        }

        sort(connected_nodes.begin(), connected_nodes.end(), greater<int>());
        if (ad_list[x].empty())
        {
            cout << "-1" << endl;
        }
        else 
        {
            for(int child : connected_nodes)
            {
                cout << child << " ";
            }
            cout << endl;
        }
    }

    return 0;
}