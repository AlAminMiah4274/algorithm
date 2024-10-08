#include <bits/stdc++.h>
using namespace std;


int dp[1005][1005];
bool exam_marks(int n, int arr[], int need)
{
    if (n == 0)
    {
        if (need == 0) return true;
        else return false;
    }
    

    if (dp[n][need] != -1) return dp[n][need];

    if (arr[n - 1] <= need)
    {
        bool chosen = exam_marks(n - 1, arr, need - arr[n - 1]);
        bool not_chosen = exam_marks(n - 1, arr, need);

        return dp[n][need] = chosen || not_chosen;
    }
    else 
    {
        return dp[n][need] = exam_marks(n - 1, arr, need);
    }
}

int main(){

    int t;
    cin >> t;
    
    while (t--)
    {
        int n, m;
        cin >> n >> m;
    
        int set_arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> set_arr[i];
        }
        
        memset(dp, -1, sizeof(dp));
        
        
        
        int need = 1000 - m;
        
        if (need < 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            if (exam_marks(n, set_arr, need)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }


    return 0;
}