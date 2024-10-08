#include <bits/stdc++.h>

using namespace std;



int main()
{
    // Write your code here
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        
        int chocolate_box[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> chocolate_box[i];
            sum += chocolate_box[i];
        }
        
        
        if (sum % 2 == 0){
            int sum_partition = sum / 2;
            
            bool chocolates[n + 1][sum_partition + 1];
            chocolates[0][0] = true;
            for (int i = 1; i <= sum_partition; i++)
            {
                chocolates[0][i] = false;
            }
            
            
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= sum_partition; j++)
                {
                    if (chocolate_box[i - 1] <= j)
                    {
                        bool chosen = chocolates[i - 1][j - chocolate_box[i - 1]];
                        bool not_chosen = chocolates[i- 1][j];
                        
                        chocolates[i][j] = chosen || not_chosen;
                    }
                    else 
                    {
                        chocolates[i][j] = chocolates[i - 1][j];
                    }
                }
            }
            
            if (chocolates[n][sum_partition]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
    }

    return 0;
}
