#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ll long long
const ll INF = 1e15 + 7;
 
 
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(2 * n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(int i = 0; i < n; ++i){
        c[2 * i] = a[i];
        c[2 * i + 1] = b[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(2));
    vector<vector<ll>> prev(n, vector<ll>(2));
    // dp[i][0] = alice didn't make her move
    // dp[i][1] = alice made her move

    dp[0][0] = dp[0][1] = max({a[0], b[0], a[0] + b[0], 0ll});
    prev[0][0] = max({a[0], b[0], a[0] + b[0]});
    prev[0][1] = max(a[0] + b[0], min(a[0], b[0]));
    for(int i = 1; i < n; ++i){
        prev[i][0] = max(a[i], b[i]);
        prev[i][1] = min(a[i], b[i]);

        prev[i][0] = max(prev[i][0], max(prev[i - 1][0], 0ll) + a[i] + b[i]);
        prev[i][1] = max(prev[i][1], max(prev[i - 1][0], 0ll) + a[i] + b[i]);
        prev[i][1] = min(prev[i][1], max(prev[i - 1][1], 0ll) + a[i] + b[i]);

        dp[i][0] = max({dp[i][0], dp[i - 1][0], prev[i][0]});
        dp[i][1] = max(dp[i - 1][1], prev[i][1]);

    }
    cout << dp[n - 1][1] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
