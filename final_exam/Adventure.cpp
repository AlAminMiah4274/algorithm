#include <bits/stc++.h>
using namespace std;
const int max_N = 1005;
const int max_W = 1005;


int top_down[max_N][max_W];
int equipment(int n, int weight[], int value[], int w)
{
    if (n == 0 || w == 0) return 0;

    if (top_down[n][w] != -1) return top_down[n][w];

    if (weight[n - 1] <= w)
    {
        int chosen = equipment(n - 1, weight, value, w - weight[n - 1]) + value[n - 1];
        int not_chosen = equipment(n - 1, weight, value, w);

        return top_down[n][w] = max(chosen, not_chosen);
    }
    else 
    {
        return top_down[n][w] = equipment(n - 1, weight, value, w);
    }

}

int main(){

    int t;
    cin >> t;

    while (t--){
        int n, w;
        cin >> n >> w;

        int weight[n], value[n];
        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }


        memset(top_down, -1, sizeof(top_down));


        cout << equipment(n, weight, value, w) << endl;
    }


    return 0;
}