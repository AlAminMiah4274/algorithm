#include <bits/stdc++.h>
using namespace std;


int subset_sum_optimization[1005][1005];
bool subset_sum(int n, int arr[], int sum)
{
    if (n == 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }


    if (subset_sum_optimization[n][sum] != -1) return subset_sum_optimization[n][sum];

    if (arr[n - 1] <= sum)
    {
        bool chosen = subset_sum(n - 1, arr, sum - arr[n - 1]);
        bool not_chosen = subset_sum(n - 1, arr, sum);

        return subset_sum_optimization[n][sum] = chosen || not_chosen;
    }
    else
    {
        bool not_chosen = subset_sum(n - 1, arr, sum);
        return subset_sum_optimization[n][sum] = not_chosen;
    }
}

int main()
{
    int n;
    cin >> n;

    int sum_arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sum_arr[i];
    }

    int sum;
    cin >> sum;

    memset(subset_sum_optimization, -1, sizeof(subset_sum_optimization));

    if (subset_sum(n, sum_arr, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}