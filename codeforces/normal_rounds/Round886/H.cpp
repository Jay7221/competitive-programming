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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        ll d;
        cin >> a >> b >> d;
        --a, --b;
        adj[b].push_back({a, d});
        adj[a].push_back({b, -d});
    }
    vector<bool> vis(n);
    vector<ll> camp(n);
    function<void(int)> dfs;
    bool ans = true;
    dfs = [&](int u){
        vis[u] = true;
        for(auto [v, d] : adj[u]){
            if(!vis[v]){
                camp[v] = camp[u] + d;
                dfs(v);
            }
            else{
                if(camp[v] != camp[u] + d){
                    ans = false;
                    return;
                }
            }
        }
    };
    for(int i = 0; (i < n) && ans; ++i){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(ans){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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
 
