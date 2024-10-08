#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        
        long long int arr[n];
        long long int arr2[n];
        for (long long int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr2[i] = arr[i];
        }
        
        sort(arr, arr + n, greater<long long int>());
        
        long long int height1 = arr[0], height2 = arr[1];
        for (long long int i = 0; i < n; i++)
        {
            if (arr2[i] == height1 || arr2[i] == height2) cout << i << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
