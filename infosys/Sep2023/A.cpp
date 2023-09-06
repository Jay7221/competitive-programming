#include <bits/stdc++.h>
 
using namespace std;
 
 
#define ll long long

void solve() {
    ll n, m;
    cin >> n;
    vector<ll> c(n + 1), f(n + 1), p(n + 1);
    for(ll i = 1; i < n + 1; ++i){
        cin >> c[i];
    }
    for(ll i = 1; i < n + 1; ++i){
        cin >> f[i];
    }
    for(ll i = 1; i < n + 1; ++i){
        cin >> p[i];
    }
    cin >> m;
    vector<ll> oc(m + 1), of(m + 1), op(m + 1);
    for(ll i = 1; i < m + 1; ++i){
        cin >> oc[i];
    }
    for(ll i = 1; i < m + 1; ++i){
        cin >> of[i];
    }
    for(ll i = 1; i < m + 1; ++i){
        cin >> op[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if((c[i] >= oc[j]) && (f[i] >= of[j])){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + op[j] - p[i]);
            }
        }
    }
    cout << dp[n][m] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
    return 0;
}
 
