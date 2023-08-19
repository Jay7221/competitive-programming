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
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
 
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
 
// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
 
struct LCA{
    vector<int> depth;
    vector<vector<int>> par;
    vector<vector<int>> adj;
    const int LOGMAX = 20;
    LCA(vector<vector<int>> &adj) : adj(adj){
        int n = adj.size();

        depth = vector<int>(n);
        par = vector<vector<int>>(n, vector<int>(LOGMAX, -1));

        dfs(0);

        for(int k = 1; k < LOGMAX; ++k){
            for(int node = 0; node < n; ++node){
                if(par[node][k - 1] != -1){
                    par[node][k] = par[par[node][k - 1]][k - 1];
                }
            }
        }
    }
    void dfs(int node, int p = -1){
        par[node][0] = p;
        for(int v : adj[node]){
            if(v != p){
                depth[v] = depth[node] + 1;
                dfs(v, node);
            }
        }
    }
    int lca(int u, int v){
        if(depth[u] < depth[v]){
            swap(u, v);
        }
        int diff = depth[u] - depth[v];
        for(int k = 0; k < LOGMAX; ++k){
            if((diff >> k) & 1){
                u = par[u][k];
            }
        }
        if(u == v){
            return u;
        }
        for(int k = LOGMAX - 1; k >= 0; --k){
            if(par[u][k] != par[v][k]){
                u = par[u][k];
                v = par[v][k];
            }
        }
        u = par[u][0];
        return u;
    }
    int dist(int u, int v){
        return ((depth[u] + depth[v]) - 2 * depth[lca(u, v)]);
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA l(adj);
    vector<int> noPath(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        int p = l.lca(u, v);
        int pp = l.par[p][0];
        ++noPath[u];
        ++noPath[v];
        --noPath[p];
        if(pp != -1){
            --noPath[pp];
        }
    }
    function<void(int, int)> dfs;
    dfs = [&](int u, int p){
        for(int v : adj[u]){
            if(v == p){
                continue;
            }
            dfs(v, u);
            noPath[u] += noPath[v];
        }
    };
    dfs(0, -1);
    for(int i = 0; i < n; ++i){
        cout << noPath[i] << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
