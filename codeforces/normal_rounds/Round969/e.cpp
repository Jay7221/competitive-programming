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
 
void dfs(int u, vector<int> &depth, vector<vector<int>> &adj){
    for(int v: adj[u]){
        depth[v] = depth[u] + 1;
        dfs(v, depth, adj);
    }
}
 
void solve() {
    int n;
    ll w;
    cin >> n >> w;
    vector<int> par(n, -1);
    vector<vector<int>> adj(n);
    for(int i = 1; i < n; ++i){
        cin >> par[i];
        --par[i];
        adj[par[i]].push_back(i);
    }

    vector<int> depth(n);
    dfs(0, depth, adj);

    // noEdges[i] = no of edges on path to (i + 1) % n that are still unassigned
    vector<int> noEdges(n);

    // depend[i] = set of u that have edge from i to par[i] in their path from u to (u + 1) % n
    vector<vector<int>> depend(n);

    for(int i = 0; i < n; ++i){
        int u = i;
        int v = (i + 1) % n;
        while(depth[u] < depth[v]){
            ++noEdges[i];
            depend[v].push_back(i);
            v = par[v];
        }
        while(depth[u] > depth[v]){
            ++noEdges[i];
            depend[u].push_back(i);
            u = par[u];
        }
        while(u != v){
            ++noEdges[i];
            depend[u].push_back(i);
            ++noEdges[i];
            depend[v].push_back(i);
            u = par[u];
            v = par[v];
        }
    }

    ll rem = n;
    ll tot = 0;
    for(int i = 0; i < n - 1; ++i){
        int u;
        ll t;
        cin >> u >> t;
        --u;
        w -= t;
        tot += 2 * t;
        for(int v: depend[u]){
            --noEdges[v];
            if(noEdges[v] == 0){
                --rem;
            }
        }
        cout << (tot + rem * w) << ' ';
    }
    cout << '\n';
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
 
