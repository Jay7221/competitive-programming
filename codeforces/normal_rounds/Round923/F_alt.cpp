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

 

vector<vector<tuple<int, int, int>>> adj;
vector<int> tin, low;
vector<bool> vis;
vector<bool> is_bridge;

int timer;

vector<int> path;

void dfs(int u, int p = -1){
    tin[u] = low[u] = timer;
    vis[u] = true;
    ++timer;

    for(auto [v, w, id]: adj[u]){
        if(v == p){
            continue;
        }
        if(vis[v]){
            low[u] = min(low[u], tin[v]);
        }
        else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(tin[u] < low[v]){
                is_bridge[id] = true;
            }
        }
    }
}
int targetNode;
bool dfs2(int u){
    vis[u] = true;
    path.push_back(u);
    if(u == targetNode){
        return true;
    }
    for(auto [v, w, id]: adj[u]){
        if(!vis[v] && dfs2(v)){
            return true;
        }
    }
    path.pop_back();
    return false;
}

void constructPath(int u, int v, int n){
    vis.assign(n, false);
    targetNode = v;
    dfs2(u);
}
 
void solve() {
    int n, m;
    cin >> n >> m;

    adj = vector<vector<tuple<int, int, int>>>(n);
    tin = vector<int>(n);
    low = vector<int>(n);
    vis = vector<bool>(n);
    is_bridge = vector<bool>(m);

    vector<tuple<int, int, int, int>> edges;

    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({u, v, w, i});
        adj[u].push_back({v, w, i});
        adj[v].push_back({u, w, i});
    }

    timer = 0;
    is_bridge.clear();
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            dfs(i);
        }
    }

    int mn = INF;

    for(auto [u, v, w, id]: edges){
        if(!is_bridge[id]){
            mn = min(mn, w);
        }
    }
    auto remove_edge = [&](int u, int v, int w, int id){
        adj[u].erase(find(adj[u].begin(),adj[u].end(), make_tuple(v, w, id)));
        adj[v].erase(find(adj[v].begin(),adj[v].end(), make_tuple(u, w, id)));
    };
    for(auto [u, v, w, id]: edges){
        if((w == mn) && !is_bridge[id]){
            remove_edge(u, v, w, id);
            path.clear();
            constructPath(u, v, n);
            cout << mn << ' ' << path.size() << '\n';
            for(int elem: path){
                cout << elem + 1 << ' ';
            }
            cout << '\n';
            return;
        }
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
 
