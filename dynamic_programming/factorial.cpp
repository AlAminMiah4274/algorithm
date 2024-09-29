#include <bits/stdc++.h>
using namespace std;


int n_factorial(int i) // O(N) 
{
    if (i == 0) return 1;

    int fact = n_factorial(i - 1);

    return fact * i;
}


int main()
{
    int n;
    cin >> n; 

    // int factorial = n_factorial(n);
    // cout << factorial << endl;

    int fact = 1; // O(N) 
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    cout << fact << endl;



    return 0;
}