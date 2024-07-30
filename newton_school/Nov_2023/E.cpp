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
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; ++i){
        int x, y, w;
        cin >> x >> y >> w;
        --x, --y;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    vector<bool> vis(n);
    vector<int> val(n);
    vector<int> basis;
    function<void(int, int)> dfs;
    auto update_basis = [&](int x){
        for(int elem : basis){
            x = min(x, x ^ elem);
        }
        if(x > 0){
            basis.push_back(x);
        }
    };
    dfs = [&](int node, int path_val){
        vis[node] = true;
        val[node] = path_val;
        for(auto pr : adj[node]){
            int nei, w;
            tie(nei, w) = pr;
            if(vis[nei]){
                update_basis(path_val ^ w ^ val[nei]);
            }
            else{
                dfs(nei, path_val ^ w);
            }
        }
    };
    dfs(0, 0);
    int ans = val[n - 1];
    for(int elem : basis){
        ans = min(ans, ans ^ elem);
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
