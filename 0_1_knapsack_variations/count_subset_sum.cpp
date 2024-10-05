#include <bits/stdc++.h>
using namespace std;

// int top_down[1005][1005];
// int count_subset_sum(int n, int arr[], int sum)
// {
//     if (n == 0)
//     {
//         if (sum == 0) return 1;
//         else return 0;
//     }

//     if (top_down[n][sum] != -1) return top_down[n][sum];


//     if (arr[n - 1] <= sum)
//     {
//         int chosen = count_subset_sum(n - 1, arr, sum - arr[n - 1]);
//         int not_chosen = count_subset_sum(n - 1, arr, sum);

//         return top_down[n][sum] = chosen + not_chosen;
//     }
//     else 
//     {
//         int not_chosen = count_subset_sum(n - 1, arr, sum);
        
//         return top_down[n][sum] = not_chosen;
//     }
// }

int main()
{
    int n;
    cin >> n;

    int set_sum[n];
    for (int i = 0; i < n; i++)
    {
        cin >> set_sum[i];
    }

    int sum;
    cin >> sum;

    // memset(top_down, -1, sizeof(top_down));
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= sum; j++)
    //     {
    //         top_down[i][j] = -1;
    //     }
    // }


    int bottom_up[n + 1][sum + 1];
    bottom_up[0][0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        bottom_up[0][i] = 0;
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (set_sum[i - 1] <= j)
            {
                int chosen = bottom_up[i - 1][j - set_sum[i - 1]];
                int not_chosen = bottom_up[i - 1][j];

                bottom_up[i][j] = chosen + not_chosen;
            }
            else 
            {
                int not_chosen = bottom_up[i - 1][j];

                bottom_up[i][j] = not_chosen;
            }
        }
    }


    cout << bottom_up[n][sum] << endl;

    return 0;
}

/*
Counted subset sum in top down and bottom up approach.
Top down approach is commented out. 
*/