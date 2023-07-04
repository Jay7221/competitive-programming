#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<ll> b = a;
    for(int i = 1; i < n; ++i){
        b[i] += b[i - 1];
    }
    ll mx = 0;
    ll ans = 0;
    ll k = 0;
    for(int i = 0; i < n; ++i){
        if((mx - b[i]) > ans){
            ans = mx - b[i];
            k = mx;
        }
        mx = max(mx, b[i]);
    }
    cout << k << '\n';
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
