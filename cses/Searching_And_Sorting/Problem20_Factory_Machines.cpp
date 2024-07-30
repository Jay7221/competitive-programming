#include<bits/stdc++.h>
using namespace std;
#define ll __int128
int main(){
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<int> k(n);
    for(int i = 0; i < n; ++i){
        cin >> k[i];
    }
    auto check = [&](ll time){
        ll prod = 0;
        for(ll kk : k){
            prod += time / kk;
        }
        return (prod >= t);
    };
    ll l = 0;
    ll r = 1e18 + 7;
    while(l < r){
        ll m = (l + r) / 2;
        if(check(m)){
            r = m;
        }
        else{
            l = m + 1;
        }
    }
    cout << (long long)l << '\n';
    return 0;
}
