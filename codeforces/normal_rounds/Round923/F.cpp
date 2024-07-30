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
const int INF = 1e9 + 7;

class DSU{
public:
    vector<int> par, rank;
    DSU(int n){
        rank = vector<int>(n, 1);
        par = vector<int>(n);
        for(int i = 0; i < n; ++i){
            par[i] = i;
        }
    }
    int get(int u){
        return (u == par[u]) ? u : par[u] = get(par[u]);
    }
    void merge(int u, int v){
        u = get(u);
        v = get(v);
        if(u == v){
            return;
        }
        if(rank[u] < rank[v]){
            swap(u, v);
        }
        par[v] = u;
        rank[u] += rank[v];
    }
};
 

vector<vector<int>> adj;
vector<bool> vis;
vector<int> path;
int targetNode;

bool dfs(int u){
    vis[u] = true;
    path.push_back(u);
    if(u == targetNode){
        return true;
    }
    for(int v: adj[u]){
        if(!vis[v] && dfs(v)){
            return true;
        }
    }
    path.pop_back();
    return false;
}
 
void solve() {
    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);
    path.clear();

    vector<tuple<int, int, int>> edges;

    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({w, u, v});
    }
    sort(edges.rbegin(), edges.rend());

    int mn = INF;
    DSU dsu(n);
    int sourceNode;
    for(auto [w, u, v]: edges){
        if(dsu.get(u) == dsu.get(v)){
            mn = w;
            sourceNode = u;
            targetNode = v;
        }
        else{
            dsu.merge(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    dfs(sourceNode);

    cout << mn << ' ' << path.size() << '\n';
    for(int elem: path){
        cout << elem + 1 << ' ' ;
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
 
