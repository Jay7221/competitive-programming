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
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);
    for(ll i = 0; i < n - 1; ++i){
        ll u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> subtree(n, 1);
    vector<ll> par(n);
    function<void(ll, ll)> dfs_subtree = [&](ll u, ll p){
        par[u] = p;
        for(ll v: adj[u]){
            if(v != p){
                dfs_subtree(v, u);
                subtree[u] += subtree[v];
            }
        }
    };

    dfs_subtree(0, -1);

    ll ans = 0;

    auto get_no_paths = [](ll no_nodes){
        return (no_nodes * (no_nodes - 1)) >> 1;
    };

    for(ll u = 0; u < n; ++u){
        ll paths_u = get_no_paths(n) - get_no_paths(n - subtree[u]);
        for(ll v: adj[u]){
            if(v != par[u]){
                paths_u -= get_no_paths(subtree[v]);
            }
        }

        for(ll v: adj[u]){
            if(v != par[u]){
                ll paths_uv = subtree[v] * (n - subtree[v]);
                ans += (paths_u - paths_uv) * get_no_paths(subtree[v]);
            }
        }


        ll paths_lca_u = get_no_paths(subtree[u]);
        for(ll v: adj[u]){
            if(v != par[u]){
                paths_lca_u -= get_no_paths(subtree[v]);
            }
        }

        ans += paths_lca_u * get_no_paths(n - subtree[u]);
    }

    ans >>= 1;
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
 
