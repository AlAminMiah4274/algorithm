#include <bits/stdc++.h>
using namespace std;

void ad_list_to_matrix(int n, vector<int> adj[])
{
    int ad_matrix[n][n];
    memset(ad_matrix, 0, sizeof(ad_matrix));

    for (int i = 0; i < n; i++)
    {
        for (int child : adj[i])
        {
            ad_matrix[i][child] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ad_matrix[i][j] << " ";
        }
        cout << endl;
    }
}


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

    ad_list_to_matrix(n, ad_list);

    return 0;
}