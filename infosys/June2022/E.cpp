#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    ll lpsum = 0;
    ll rpsum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
        rpsum += i * a[i];
    }
    ll lsum = 0;
    ll rsum = sum;
    ll ans = 0;
    for(int k = 0; k < n; ++k){
        rsum -= a[k];
        rpsum -= k * a[k];

        ll cur = sum + k * lsum - lpsum + rpsum - k * rsum;
        ans = max(ans, cur);

        lsum += a[k];
        lpsum += k * a[k];
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
