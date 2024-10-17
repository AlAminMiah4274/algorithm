#include <bits/stdc++.h>
using namespace std;



int dp[1005][1005];
int un_knapsack(int n, vector<int> weight, vector<int> value, int cap)
{
    if (n == 0 || cap == 0) return 0;

    if (dp[n][cap] != -1) return dp[n][cap];
    

    if (weight[n - 1] <= cap)
    {
        int chosen = un_knapsack(n, weight, value, cap - weight[n - 1]) + value[n - 1];
        int not_chosen = un_knapsack(n - 1, weight, value, cap);

        return dp[n][cap] = max(chosen, not_chosen);
    }
    else 
    {
        return dp[n][cap] = un_knapsack(n - 1, weight, value, cap);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    vector<int> value(n), weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
        weight[i] = i + 1;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << un_knapsack(n, weight, value, n) << "\n";



    return 0;
}