#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
const ll MOD = 1e9 + 7;
const ll INF = 1e15 + 7;
void solve(){
    int n;
    cin >> n;
    vector<ll> c(n);
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    Graph g(n);
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g.add(u, v);
    }

    SCC s(g);
    vector<int> root = s.root;
    int N = s.numCom;

    vector<ll> min_c(N, INF);
    vector<int> f(N);

    for(int i = 0; i < n; ++i){
        int r = root[i];
        if(c[i] == min_c[r]){
            ++f[r];
        }else if(c[i] < min_c[r]){
            f[r] = 1;
            min_c[r] = c[i];
        }
    }
    ll money = 0, no_ways = 1;
    for(int r = 0; r < N; ++r){
        money += min_c[r];
        no_ways = (no_ways * f[r]) % MOD;
    }
    cout << money << ' ' << no_ways << '\n';

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
