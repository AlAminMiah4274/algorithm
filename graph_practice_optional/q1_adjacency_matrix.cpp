#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int n, e;
    cin >> n >> e;

    int ad_matrix[n][n];
    memset(ad_matrix, 0, sizeof(ad_matrix));

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        ad_matrix[a][b] = 1;
        ad_matrix[b][a] = 1;
    }

    if (ad_matrix[0][5])
    {
        cout << "Connected" << endl;
    }
    else
    {
        cout << "Not connected" << endl;
    }

    return 0;
}