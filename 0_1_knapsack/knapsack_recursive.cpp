#include <bits/stdc++.h>
using namespace std;



int knapsack(int n, int weight[], int value[], int W)
{
    if (n == 0) return 0;
    if (W == 0) return 0;

    if (weight[n - 1] <= W)
    {
        int option1 = knapsack(n - 1, weight, value, W - weight[n - 1]) + value[n - 1];
        int option2 = knapsack(n - 1, weight, value, W);

        return max(option1, option2);
    }
    else 
    {
        return knapsack(n - 1, weight, value, W);
    }
}


int main()
{
    int n;
    cin >> n;

    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }


    int W;
    cin >> W;

    
    cout << knapsack(n, weight, value, W) << endl;


    return 0;
}