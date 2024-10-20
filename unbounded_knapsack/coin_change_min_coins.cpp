#include <bits/stdc++.h>
using namespace std;
const int N = 1005;


int dp[N][N];
int min_coins(int n, vector<int> arr, int amount)
{
    if (n == 0)
    {
        if (amount == 0) return 0;
        else return INT_MAX;
    }


    if (dp[n][amount] != -1) return dp[n][amount];

    if (arr[n - 1] <= amount)
    {
        int chosen = min_coins(n, arr, amount - arr[n - 1]) + 1;
        int not_chosen = min_coins(n - 1, arr, amount);

        return dp[n][amount] = min(chosen, not_chosen);
    }
    else 
    {
        return dp[n][amount] = min_coins(n - 1, arr, amount);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int amount;
    cin >> amount;


    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            dp[i][j] = -1;
        }
    }


    cout << min_coins(n, coins, amount) << "\n";



    return 0;
}