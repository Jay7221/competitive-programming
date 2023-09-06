#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void solve(){
    int n;
    cin >> n;
    if(isPrime(n)){
        cout << "KP\n";
    }
    else{
        cout << "Viraj\n";
    }
}
int main(){
    solve();
}
