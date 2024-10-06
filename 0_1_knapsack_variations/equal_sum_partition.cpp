#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int equal_sum[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> equal_sum[i];
        sum += equal_sum[i];
    }

    if (sum % 2 == 0)
    {
        int sum_partition = sum / 2;

        bool equal_sum_partition[n + 1][sum_partition + 1];
        equal_sum_partition[0][0] = true;
        for (int i = 1; i <= sum_partition; i++)
        {
            equal_sum_partition[0][i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum_partition; j++)
            {
                if (equal_sum[i - 1] <= j)
                {
                    bool chosen = equal_sum_partition[i - 1][j - equal_sum[i - 1]];
                    bool not_chosen = equal_sum_partition[i - 1][j];

                    equal_sum_partition[i][j] = chosen || not_chosen;
                }
                else 
                {
                    bool not_chosen = equal_sum_partition[i - 1][j];

                    equal_sum_partition[i][j] = not_chosen;
                }
            }
        }

        if (equal_sum_partition) cout << "YES" << endl;

    }
    else 
    {
        cout << "NO" << endl;
    }




    return 0;
}