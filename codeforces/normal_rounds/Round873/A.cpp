#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll a, ll b){
    return ((a + b) % MOD);
}
ll mult(ll a, ll b){
    return ((a * b) % MOD);
}
void solve(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 1;
    for(int i = 0; i < n; ++i){
        ll tmp = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        tmp -= i;
        tmp = max(tmp, 0ll);
        ans = mult(ans, tmp);
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
