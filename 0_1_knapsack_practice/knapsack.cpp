#include <bits/stdc++.h>
using namespace std;




int knapsack(int n, int weight[], int value[], int W)
{
    if (n == 0 || W == 0) return 0;
    
    if (weight[n - 1] <= W)
    {
        int chosen = knapsack(n - 1, weight, value, W - weight[n - 1]) + value[n - 1];
        int not_chosen = knapsack(n - 1, weight, value, W);
        
        return max(chosen, not_chosen);
    }
    else 
    {
        return knapsack(n - 1, weight, value, W);
    }
}


int main()
{
    int n, W;
    cin >> n >> W;
    
    
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        
        weight[i] = a;
        value[i] = b;
    }
    
    
    cout << knapsack(n, weight, value, W) << endl;
    
    
    return 0;
}