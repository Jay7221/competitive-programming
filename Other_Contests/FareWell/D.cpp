#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin >> n;
    auto calc = [&](ll k){
        ll ans = 13 * k * (k + 1);
        return ans;
    };
    auto get = [&](ll n){
        ll l = 0, r = 1e8;
        while(l < r){
            ll m = (l + r) / 2;
            if(calc(m) < n){
                l = m + 1;
            }else{
                r  = m;
            }
        }
        n -= calc(l - 1);
        --n;
        n /= l;
        return (char)('A' + n);
    };
    cout << get(n) << '\n';
}
int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
