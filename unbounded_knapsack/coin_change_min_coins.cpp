#include <bits/stdc++.h>
#define ll long long 
using namespace std;


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


    ll dp[n + 1][amount + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= amount; i++) dp[0][i] = INT_MAX - 1;


    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
            {
                ll chosen = dp[i][j - coins[i - 1]] + 1;
                ll not_chosen = dp[i - 1][j];

                dp[i][j] = min(chosen, not_chosen);
            }
            else 
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }


    // cout << dp[n][amount] << "\n";


    if (dp[n][amount] == INT_MAX - 1) cout << "Not Possible" << "\n";
    else cout << dp[n][amount] << "\n";


    return 0;
}