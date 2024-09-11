#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int ad_matrix[n][n];
    memset(ad_matrix, -1, sizeof(ad_matrix));

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        ad_matrix[a][b] = 1;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (ad_matrix[x][y] == 1 || x == y)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}