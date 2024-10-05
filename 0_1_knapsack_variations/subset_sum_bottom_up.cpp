#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;

    int set_arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> set_arr[i];
    }

    int sum;
    cin >> sum;


    bool bottom_up[n + 1][sum + 1];
    bottom_up[0][0] = true;
    for (int i = 1; i <= sum; i++)
    {
        bottom_up[0][i] = false;
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (set_arr[i - 1] <= j)
            {
                bool chosen = bottom_up[i - 1][j - set_arr[i - 1]];
                bool not_chosen = bottom_up[i - 1][j];

                bottom_up[i][j] = chosen || not_chosen;
            }
            else 
            {
                bool not_chosen = bottom_up[i - 1][j];
                bottom_up[i][j] = not_chosen;
            }
        }
    }


    if (bottom_up[n][sum]) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}