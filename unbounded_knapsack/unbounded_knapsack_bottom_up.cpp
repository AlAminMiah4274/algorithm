#include <bits/stdc++.h>
using namespace std;


int main()
{
int n, W;
cin >> n >> W;

int weight[n], value[n];
for (int i = 0; i < n; i++)
{
cin >> weight[i];
}

for (int i = 0; i < n; i++)
{
cin >> value[i];
}

int dp[n + 1][W + 1];
for (int i = 0; i <= n; i++){
for (int j = 0; j <= W; j++)
{
if (i == 0 || j == 0) dp[i][j] = 0;
}
}


for (int i = 1; i <= n; i++)
{
for (int j = 1; j <= W; j++)
{
if (weight[i - 1] <= W)
{
int chosen = value[i - 1] + dp[i][j - weight[i - 1]];
int not_chosen = dp[i - 1][j];

dp[i][j] = max(chosen, not_chosen);
}
else
{
dp[i][j] = dp[i - 1][j];
}
}
}

cout << dp[n][W] << endl;


return 0;
}
