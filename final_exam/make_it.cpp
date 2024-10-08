#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;


int input;
int top_down[N];
bool reach(int n){
    
    if (n > input) return false;

    if (n == input) return true;
    
    if (top_down[n] != -1) return top_down[n];

    return top_down[n] = reach(n + 3) || reach(n * 2);
}

int main(){

    int t;
    cin >> t;


    while (t--){
        
        cin >> input;
        
        memset(top_down, -1, sizeof(top_down));

        int flag = reach(1);
        

        if (flag == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }



    return 0;
}