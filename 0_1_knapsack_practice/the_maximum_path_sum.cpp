#include <bits/stdc++.h>
using namespace std;
const int matrix_n = 10;
const int matrix_m = 10;

int max_path_sum[matrix_n][matrix_m];
int path_sum(int n, int m)
{
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> max_path_sum[i][j];
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << max_path_sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}