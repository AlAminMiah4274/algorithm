#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;


    int set_sum[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> set_sum[i];
        sum += set_sum[i];
    }

    int given_sum;
    cin >> given_sum;


    bool difference_count[n + 1][sum + 1];
    difference_count[0][0] = true;
    for (int i = 1; i <= sum; i++)
    {
        difference_count[0][i] = false;
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (set_sum[i - 1] <= j)
            {
                bool chosen = difference_count[i - 1][j - set_sum[i - 1]];
                bool not_chosen = difference_count[i - 1][j];

                difference_count[i][j] = chosen || not_chosen;
            }
            else 
            {
                bool not_chosen = difference_count[i - 1][j];

                difference_count[i][j] = not_chosen;
            }
        }
    }


    vector<int> sum_of_subset;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (difference_count[i][j])
                sum_of_subset.push_back(j);
        }
    }

    // int ans = 0;
    int count = 0;
    for (int e : sum_of_subset)
    {
        int set1 = e;
        int set2 = sum - set1;

        // ans = abs(set1 - set2);

        if (given_sum == abs(set1 - set2))
        {
            count++;
        }
    }

    cout << count;


    return 0;
}