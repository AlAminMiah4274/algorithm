#include <bits/stdc++.h>
using namespace std;


int dp[1005][1005];
int target_sum(int n, int arr[], int sum)
{
    if (n == 0)
    {
        if (sum == 0) return 1;
        else return 0;
    }

    if (dp[n][sum] != -1) return dp[n][sum];

    if (arr[n - 1] <= sum)
    {
        int chosen = target_sum(n - 1, arr, sum - arr[n - 1]);
        int not_chosen = target_sum(n - 1, arr, sum);

        return dp[n][sum] = chosen + not_chosen;
    }
    else 
    {
        return dp[n][sum] = target_sum(n - 1, arr, sum);
    }
}

int main(){

    int n;
    cin >> n;

    int set_arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> set_arr[i];
        sum += set_arr[i];
    }

    int target;
    cin >> target;

    memset(dp, -1, sizeof(dp));

    int set1 = (target + sum) / 2;
    if (set1 < 0) return 0;
    if (target > sum || (target + sum) % 2 == 1) return 0;


    cout << target_sum(n, set_arr, set1);


    return 0;
}