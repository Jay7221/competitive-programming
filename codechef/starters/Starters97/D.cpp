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
 
 
class Edge{
    public:
        int u, v, id;
        Edge(int u, int v, int id){
            this -> u = u;
            this -> v = v;
            this -> id = id;
        }
};
class Graph{
    public:
        int n, m;
        vector<vector<Edge>> adj;
        vector<Edge> edges;
        Graph(){
            n = 0;
            m = 0;
        }
        Graph(int n){
            this -> n = n;
            m = 0;
            adj = vector<vector<Edge>>(n);
        }
        void add(int u, int v){
            adj[u].push_back(Edge(u, v, m));
            edges.push_back(Edge(u, v, m));
            ++m;
        }
};
class SCC{
    public:
        Graph g, g_rev;
        vector<bool> vis;
        vector<int> order, root;
        int numCom;

        void dfs1(int u){
            vis[u] = true;
            for(Edge e : g.adj[u]){
                if(!vis[e.v]){
                    dfs1(e.v);
                }
            }

            order.push_back(u);
        }

        void dfs2(int u){
            vis[u] = true;
            root[u] = numCom;
            for(Edge e : g_rev.adj[u]){
                if(!vis[e.v]){
                    dfs2(e.v);
                }
            }
        }

        SCC(){
        }
        SCC(Graph g){
            this -> g = g;

            g_rev = Graph(g.n);
            for(Edge e : g.edges){
                g_rev.add(e.v, e.u);
            }

            root.assign(g.n, -1);
            vis.assign(g.n, false);

            for(int i = 0; i < g.n; ++i){
                if(!vis[i]){
                    dfs1(i);
                }
            }

            reverse(order.begin(), order.end());

            vis.assign(g.n, false);
            numCom = 0;

            for(int u : order){
                if(!vis[u]){
                    dfs2(u);
                    ++numCom;
                }
            }
        }

        Graph get_condensed_graph(){
            set<pair<int, int>> edges;
            for(Edge e : g.edges){
                int u = root[e.u];
                int v = root[e.v];
                if(u != v){
                    edges.insert({u, v});
                }
            }
            Graph res(numCom);
            for(auto [u, v] : edges){
                res.add(u, v);
            }
            return res;
        }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g.add(u, v);
    }
    SCC s(g);
    int N = s.numCom;
    vector<ll> sz(N);
    for(int i = 0; i < n; ++i){
        ++sz[s.root[i]];
    }

    sort(sz.rbegin(), sz.rend());

    vector<ll> cost(N);
    vector<ll> pre = sz;
    for(int i = 1; i < N; ++i){
        cost[i] = cost[i - 1] + pre[i - 1] * sz[i];
        pre[i] += pre[i - 1];
    }

    auto get = [&](ll k){
        int l = 0, r = N - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(cost[mid] > k){
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        return l;
    };

    int q;
    cin >> q;
    while(q--){
        ll k;
        cin >> k;
        int i = get(k);
        ll ans = pre[i];
        if(i < N - 1){
            ll l = 0, r = sz[i + 1];
            while(l < r){
                ll mid = (l + r + 1) / 2;
                if(pre[i] * mid + cost[i] > k){
                    r = mid - 1;
                }else{
                    l = mid;
                }
            }
            ans += l;
        }
        cout << ans << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
