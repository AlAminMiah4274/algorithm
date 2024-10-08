#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;


int input;
bool reach(int n){
    
    if (n > input) return false;

    if (n == input) return true;

    return reach(n * 30) || reach(n * 20);
}

int main(){

    int t;
    cin >> t;


    while (t--){
        
        cin >> input;

        bool flag = reach(1);
        

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }



    return 0;
}