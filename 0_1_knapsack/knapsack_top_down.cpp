#include <bits/stdc++.h>
using namespace std;
const int max_n = 1000;
const int max_w = 1000;


// complexity: O(n * w) 
int top_down[max_n][max_w];

int knapsack(int n, int weight[], int value[], int W)
{
    if (n == 0 || W == 0)
        return 0;

    if (top_down[n][W] != -1)
        return top_down[n][W];

    if (weight[n - 1] <= W)
    {
        int chosen = knapsack(n - 1, weight, value, W - weight[n - 1]) + value[n - 1];
        int not_chosen = knapsack(n - 1, weight, value, W);

        return top_down[n][W] = max(chosen, not_chosen);
    }
    else
    {
        return top_down[n][W] = knapsack(n - 1, weight, value, W);
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

    // for setting value of the 2D array
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            top_down[i][j] = -1;
        }
    }

    cout << knapsack(n, weight, value, W) << endl;

    return 0;
}