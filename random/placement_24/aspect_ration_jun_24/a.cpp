#include<bits/stdc++.h>
using namespace std;
int Factorial(int n){
    int ans = 1;
    for(int i = 1; i <= n; ++i){
        ans *= i;
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << Factorial(n) << '\n';
    }
    return 0;
}
