#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int W;
    cin >> W;

    int bottom_up[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                bottom_up[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weight[i - 1] <= j)
            {
                int chosen = bottom_up[i - 1][j - weight[i - 1]] + value[i - 1];
                int not_chosen = bottom_up[i - 1][j];

                bottom_up[i][j] = max(chosen, not_chosen);
            }
            else 
            {
                int not_chosen = bottom_up[i - 1][j];
                bottom_up[i][j] = not_chosen;
            }
        }
    }


    cout << bottom_up[n][W] << endl;

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= W; j++)
    //     {
    //         cout << bottom_up[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}