#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int LOGMAX = 31;
ll power(ll a, ll p){
    ll ans = 1, rem = a;
    while(p > 0){
        if(p & 1){
            ans *= rem;
        }
        rem *= rem;
        p >>= 1;
    }
    return ans;
}
void solve(){
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    if(l == 0){
        ans = 1;
    }
    for(ll b = 1; b <= r; b <<= 1){
        ans += max(0ll, b - l);
    }
    cout << ans << '\n';
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
