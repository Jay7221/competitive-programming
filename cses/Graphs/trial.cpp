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

void solve(){
    int n, m;
    cin >> n >> m;
    Graph g(n);
    vector<ll> c(n);
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g.add(u, v);
    }

    SCC s(g);
    g = s.get_condensed_graph();

    vector<ll> coin(g.n), par(g.n);
    for(int i = 0; i < n; ++i){
        coin[s.root[i]] += c[i];
    }

    s = SCC(g);
    vector<int> order = s.order;
    for(int u : order){
        coin[u] += par[u];
        for(Edge e : g.adj[u]){
            par[e.v] = max(par[e.v], coin[u]);
        }
    }
    cout << *max_element(coin.begin(), coin.end()) << '\n';
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
