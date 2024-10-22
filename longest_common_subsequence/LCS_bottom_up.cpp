#include <bits/stdc++.h>
using namespace std;


int main()
{
    string a, b;
    cin >> a >> b;


    int lcs[a.size() + 1][b.size() + 1];
    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            if (i == 0 || j == 0) lcs[i][j] = 0;
        }
    }


    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else 
            {
                int ans1 = lcs[i - 1][j];
                int ans2 = lcs[i][j - 1];

                lcs[i][j] = max(ans1, ans2);
            }
        }
    }

    cout << lcs[a][b] << "\n";



    return 0;
}