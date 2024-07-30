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
 
class DSU{
    public:
        vector<int> par;
        vector<int> rank;
        int n;
        DSU(){
            n = 0;
        }
        DSU(int n){
            this -> n = n;
            par = vector<int>(n);
            for(int i = 0; i < n; ++i){
                par[i] = i;
            }
            rank = vector<int>(n, 1);
        }
        int get_par(int u){
            if(par[u] == u){
                return u;
            }
            return par[u] = get_par(par[u]);
        }
        int get_size(int u){
            u = get_par(u);
            return rank[u];
        }
        void merge(int u, int v){
            u = get_par(u);
            v = get_par(v);
            if(u == v){
                return;
            }
            if(rank[u] < rank[v]){
                swap(u, v);
            }
            par[v] = u;
            rank[u] += rank[v];
            --n;
        }
        int size(){
            return n;
        }
};

int n, m;
vector<vector<int>> adj; // adjacency list of graph
vector<tuple<int, int, ll>> edges;
vector<vector<pair<int, ll>>> graph;

vector<bool> visited;
vector<int> tin, low;
vector<pair<int, int>> bridges;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                bridges.push_back({v, to});
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
void get_bridges(){
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            dfs(i);
        }
    }
}
bool check(ll limit){
    vector<int> deg(n);
    vector<ll> dp(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto [u, v, k] : edges){
        ++deg[u];
        ++deg[v];
    }
    for(int i = 0; i < n; ++i){
        pq.push({deg[i], i});
    }
    vector<bool> vis(n);
    while(!pq.empty()){
        int _, u;
        tie(_, u) = pq.top();
        pq.pop();

        vis[u] = true;

        for(auto [v, cost] : graph[u]){
            if(vis[v]){
                continue;
            }
            ll diff = min(limit - dp[u], cost);
            dp[u] += diff;
            dp[v] += cost - diff;
        }
    }
    for(int i = 0; i < n; ++i){
        if(dp[i] > limit){
            return false;
        }
    }
    return true;
}

ll dfs2(int u, int p = -1){
    ll size_u = 1;
    visited[u] = true;
    for(auto [v, cost] : graph[u]){
        if(visited[v]){
            continue;
        }
        ll size_v = dfs2(v, u);
        cost *= size_v;
        cost *= n - size_v;
        edges.push_back({u, v, cost});
        size_u += size_v;
    }
    return size_u;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    adj.assign(n, vector<int>());
    for(int i = 0; i < m; ++i){
        int u, v, k;
        cin >> u >> v >> k;
        --u, --v;
        edges.push_back({u, v, k});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    get_bridges();

    vector<bool> is_bridges(n * n);
    for(auto [u, v] : bridges){
        is_bridges[u * n + v] = is_bridges[u + n * v] = true;
    }
    DSU dsu(n);
    for(auto [u, v, k] : edges){
        if(!is_bridges[u * n + v]){
            dsu.merge(u, v);
        }
    }
    graph.assign(n, vector<pair<int,ll>>());
    for(auto [u, v, k] : edges){
        if(!is_bridges[u * n + v]){
            continue;
        }
        ll cost = k;
        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }
    edges.clear();

    visited.assign(n, false);
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            dfs2(i);
        }
    }
    graph.assign(n, vector<pair<int, ll>>());
    for(auto [u, v, cost] : edges){
        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }

    ll l = 0, r = n * 1ll * n * 1ll * 1e5;
    r = 4;
    while(l < r){
        ll m = (l + r) / 2;
        if(check(m)){
            r = m;
        }
        else{
            l = m + 1;
        }
    }
    cout << l << '\n';
}
