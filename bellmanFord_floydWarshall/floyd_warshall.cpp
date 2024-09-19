#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int node, edge;
    cin >> node >> edge;

    ll ad_matrix[node][node];
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            ad_matrix[i][j] = INT_MAX;

            if (i == j)
            {
                ad_matrix[i][j] = 0;
            }
        }
    }

    while (edge--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        ad_matrix[a][b] = c;
    }

    for (int k = 0; k < node; k++)
    {
        for (int i = 0; i < node; i++)
        {
            for (int j = 0; j < node; j++)
            {
                if (ad_matrix[i][k] + ad_matrix[k][j] < ad_matrix[i][j])
                {
                    ad_matrix[i][j] = ad_matrix[i][k] + ad_matrix[k][j];
                }
            }
        }
    }

    // for (int i = 0; i < node; i++)
    // {
    //     for (int j = 0; j < node; j++)
    //     {
    //         if (ad_matrix[i][j] == INT_MAX)
    //         {
    //             cout << "INF" << " ";
    //         }
    //         else
    //         {
    //             cout << ad_matrix[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }


    for (int i = 0; i < node; i++)
    {
        if (ad_matrix[i][i] < 0)
        {
            cout << "cycle detected" << endl;
            break;
        }
    }

    return 0;
}