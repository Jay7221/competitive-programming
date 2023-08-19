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
#define ld long double
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
 
void solve() {
    int n, s;
    cin >> n >> s;
    const ll MOD = 998244353;
    vector<vector<pair<int, int>>> tree(n);
    function<void(int, int)> dfs;
    vector<ll> dp(n, 1), sz(n, 1);
    ll ans = 1;
    // dp[i] = num of graphs in subtree of i
    dfs = [&](int u, int p){
        for(auto [v, w] : tree[u]){
            if(v == p){
                continue;
            }
            dfs(v, u);
            dp[u] *= dp[v];
            dp[u] *= (1 + (sz[u] * sz[v] - 1) * (s - w));
            sz[u] += sz[v];
        }
        return sz;
    };
    for(int i = 0; i < n - 1; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }
    dfs(0, -1);
    cerr << dp << '\n';
    cout << dp[0] << '\n';
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
 
