#include<bits/stdc++.h>
using namespace std;
#define ll long long
int getSmallestPrimeDiv(int k){
    for(int i = 2; i * i <= k; ++i){
        if(k % i == 0){
            return i;
        }
    }
    return k;
}
void solve(){
    int n, k;
    cin >> n >> k;
    if(n == 1 || k == 1){
        cout << "Alice" << endl;
        cout << n << endl;
        cin >> n;
        return;
    }
    int p = getSmallestPrimeDiv(k);
    bool turn;
    if((n % p) == 0){
        turn = false;
    }else{
        turn = true;
    }
    if(turn){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
    }
    while(n > 0){
        if(turn){
            cout << (n % p) << endl;
        }else{
            cin >> n;
        }
        turn ^= 1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

