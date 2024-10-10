#include <bits/stdc++.h>
using namespace std;


int dp[1005][1005];
int unbounded_knapsack(int n, int w_arr[], int v_arr[], int W)
{
    if (n == 0 || W == 0) return 0;

    if (dp[n][W] != -1) return dp[n][W];

    if (w_arr[n - 1] <= W)
    {
        int chosen = v_arr[n - 1] + unbounded_knapsack(n, w_arr, v_arr, W - w_arr[n - 1]);
        int not_chosen = unbounded_knapsack(n - 1, w_arr, v_arr, W);

        return dp[n][W] = max(chosen, not_chosen);
    }
    else 
    {
        return dp[n][W] = unbounded_knapsack(n - 1, w_arr, v_arr, W);
    }
}

int main()
{
    int n, W;
    cin >> n >> W;

    // to set every cell -1
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }

    int value[n], weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }


    cout << unbounded_knapsack(n, weight, value, W) << endl;


    return 0;
}