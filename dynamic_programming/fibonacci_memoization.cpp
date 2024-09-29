#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1e5 + 5;


ll dp[N];
ll fibo(int i)
{

    // complexity: O(N) 

    if (i == 0 || i == 1) return i;

    if (dp[i] != -1) return dp[i];

    ll ans = fibo(i - 1) + fibo(i - 2);
    dp[i] = ans;

    return ans;
}


int main()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << fibo(n) << endl;

    return 0;
}