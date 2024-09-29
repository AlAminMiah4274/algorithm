#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;

    int bottom_up[n];
    bottom_up[0] = 0;
    bottom_up[1] = 1;

    // complexity: O(N) 

    for (int i = 2; i <= n; i++)
    {
        bottom_up[i] = bottom_up[i - 1] + bottom_up[i - 2];
    }

    cout << bottom_up[n] << endl;


    return 0;
}