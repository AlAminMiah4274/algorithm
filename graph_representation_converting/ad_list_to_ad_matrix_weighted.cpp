#include <bits/stdc++.h>
using namespace std;


void ad_list_to_ad_matrix(int n, vector<pair<int, int>> adj[])
{
    int ad_matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ad_matrix[i][j] = -1;
            if (i == j) ad_matrix[i][j] = 0;
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (pair<int, int> child : adj[i])
        {
            int child_node = child.first;
            int cost = child.second;

            ad_matrix[i][child_node] = cost;
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


    vector<pair<int, int>> ad_list[n];
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        ad_list[a].push_back({b, c});
        ad_list[b].push_back({a, c});
    }

    ad_list_to_ad_matrix(n, ad_list);


    return 0;
}