#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll l = 0;
    ll r = accumulate(a.begin(), a.end(), 0ll);
    auto check = [&](ll m){
        ll sum = 0;
        for(int i = 0; i < n; ++i){
            sum += min(a[i], m);
        }
        return (k * m <= sum);
    };
    while(l < r){
        ll m = (l + r + 1) / 2;
        if(check(m)){
            l = m;
        }else{
            r = m - 1;
        }
    }
    ll ans = l;
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
