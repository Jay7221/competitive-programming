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
    vector<ll> a(n + 1), b(n + 1);
    vector<ll> c(2 * n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    int N = 2 * n + 2;
    vector<ll> dp(N), rdp(N);

    for(int i = 1; i <= n; ++i){
        dp[2 * i - 1] = max({ 0ll, max(a[i], b[i]) + dp[2 * i - 2] });
        dp[2 * i] = max({ 0ll, a[i], b[i], a[i] + b[i] + dp[2 * i - 2] });
    }
    for(int i = n; i > 0; --i){
        rdp[2 * i] = max({ 0ll, max(a[i], b[i]) + rdp[2 * i + 1] });
        rdp[2 * i - 1] = max({ 0ll, a[i], b[i], a[i] + b[i] + rdp[2 * i + 1] });
    }
    vector<ll> pre = dp, suf = rdp;
    for(int i = 1; i < N; ++i){
        pre[i] = max(pre[i], pre[i - 1]);
    }
    for(int i = N - 2; i >= 0; --i){
        suf[i] = max(suf[i], suf[i + 1]);
    }
    ll ans = INF;
    for(int x = 1; x <= n; ++x){
        ll tmp;
        tmp = max({ 0ll, pre[2 * x - 2], suf[2 * x + 1], dp[2 * x - 2] + a[x], b[x] + rdp[2 * x + 1], dp[2 * x - 2] + a[x] + b[x] + rdp[2 * x + 1] });
        ans = min(ans, tmp);

        tmp = max({ 0ll, pre[2 * x - 2], suf[2 * x + 1], dp[2 * x - 2] + b[x], a[x] + rdp[2 * x + 1], dp[2 * x - 2] + b[x] + a[x] + rdp[2 * x + 1] });
        ans = min(ans, tmp);
    }
    cout << ans << '\n';
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
 
