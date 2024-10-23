#include <bits/stdc++.h>
using namespace std;
const int N = 1005;


// complexity: ---> O(n * m);

int dp[N][N];
int LCS(string a, int n, string b, int m)
{
    if (n == 0 || m == 0) return 0;

    if (dp[n][m] != -1) return dp[n][m];


    if (a[n - 1] == b[m - 1])
    {
        int ans = LCS(a, n - 1, b, m - 1);

        return dp[n][m] = ans + 1;
    }
    else
    {
        int ans1 = LCS(a, n - 1, b, m);
        int ans2 = LCS(a, n, b, m - 1);

        return dp[n][m] = max(ans1, ans2);
    }
}


int main()
{
    string str_a, str_b;
    cin >> str_a >> str_b;


    for (int i = 0; i <= str_a.size(); i++)
    {
        for (int j = 0; j <= str_b.size(); j++)
        {
            dp[i][j] = -1;
        }
    }



    cout << LCS(str_a, str_a.size(), str_b, str_b.size()) << "\n";


    return 0;
}