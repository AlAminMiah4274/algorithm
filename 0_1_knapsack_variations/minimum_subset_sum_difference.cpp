#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int subset_sum[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> subset_sum[i];
        sum += subset_sum[i];
    }

    bool minimum_difference[n + 1][sum + 1];
    minimum_difference[0][0] = true;
    for (int i = 1; i <= sum; i++) {
        minimum_difference[0][i] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
        if (subset_sum[i - 1] <= j) {
            bool chosen = minimum_difference[i - 1][j - subset_sum[i - 1]];
            bool not_chosen = minimum_difference[i - 1][j];
            minimum_difference[i][j] = chosen || not_chosen;
        } else {
            bool not_chosen = minimum_difference[i - 1][j];
            minimum_difference[i][j] = not_chosen;
        }
        }
    }

    vector<int> minimum_sum;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (minimum_difference[i][j] == true){
                minimum_sum.push_back(j);
            }
        }
    }


    int ans = INT_MAX;
    for (int e : minimum_sum)
    {
        int set1 = e;
        int set2 = sum - set1;
        ans = min(ans, abs(set1 - set2));
    }

    cout << ans << endl;


    return 0;
}