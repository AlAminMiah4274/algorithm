#include <bits/stdc++.h>
using namespace std;


int fibo(int i)
{
    if (i == 0 || i == 1)
    {
        return i;
    }

    // complexity: O(2^n)  

    int fibo_num = fibo(i - 1) + fibo(i - 2);

    return fibo_num;
}


int main()
{
    int n;
    cin >> n;

    cout << fibo(n) << endl;

    return 0;
}