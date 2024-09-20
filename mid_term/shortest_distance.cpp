#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const long long int INF = 1e18 + 5;



int main()
{
    // Write your code here
    int node, edge;
    cin >> node >> edge;
    
    long long ad_matrix[node + 5][node + 5];
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            ad_matrix[i][j] = INF;
            if (i == j)
            {
                ad_matrix[i][j] = 0;
            }
        }
    }
    
    while (edge--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        
        // ad_matrix[a][b] = w;
        if (ad_matrix[a][b] == INF || ad_matrix[a][b] > w)
        {
            ad_matrix[a][b] = w;
        }
    }
    
    int q;
    cin >> q;
    
    
    
    for (int k = 1; k <= node; k++)
    {
        for (int i = 1; i <= node; i++)
        {
            for (int j = 1; j <= node; j++)
            {
                if ((ad_matrix[i][k] + ad_matrix[k][j]) < ad_matrix[i][j])
                {
                    ad_matrix[i][j] = ad_matrix[i][k] + ad_matrix[k][j];
                }
            }
        }
    }
    
    
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        
        if (ad_matrix[x][y] == INF)
        {
            cout << "-1" << endl;
        }
        else 
        {
            cout << ad_matrix[x][y] << endl;
        }
    }
    
    

    return 0;
}