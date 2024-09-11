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
    }

    for (int i = 0; i < ad_list[5].size(); i++)
    {
        cout << ad_list[5][i] << " ";
    }

    return 0;
}