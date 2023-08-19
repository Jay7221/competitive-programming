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
            adj[v].push_back(Edge(v, u, m));
            edges.push_back(Edge(u, v, m));
            ++m;
        }
};
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
class FindBridges{
    public:
        Graph g;
        vector<bool> visited;
        vector<int> tin, low;
        int timer;
        vector<bool> isBridge;
        vector<int> bridges;

        void is_bridge(Edge e){
            isBridge[e.id] = true;
        }
        void dfs(int u, int id = -1){
            visited[u] = true;
            tin[u] = low[u] = timer;
            ++timer;

            for(Edge e : g.adj[u]){
                if(e.id == id){
                    continue;
                }
                if(visited[e.v]){
                    low[u] = min(low[u], tin[e.v]);
                }
                else{
                    dfs(e.v, e.id);
                    low[u] = min(low[u], low[e.v]);
                    if(tin[u] < low[e.v]){
                        is_bridge(e);
                    }
                }
            }
        }
        FindBridges(){
        }
        FindBridges(Graph g){
            timer = 0;
            this -> g = g;
            tin = vector<int>(g.n);
            low = vector<int>(g.n);
            visited = vector<bool>(g.n);
            isBridge = vector<bool>(g.m);
            dfs(0);
            for(int i = 0; i < g.m; ++i){
                if(isBridge[i]){
                    bridges.push_back(i);
                }
            }
        }
        vector<int> get_bridges(){
            return bridges;
        }
};
class BCC{
    public:
        Graph g;
        Graph res;
        map<int, int> mp;
        BCC(){
        }
        BCC(Graph g){
            this -> g = g;
            FindBridges f(g);
            DSU dsu(g.n);
            for(Edge e : g.edges){
                if(!f.isBridge[e.id]){
                    dsu.merge(e.u, e.v);
                }
            }
            for(int i = 0; i < g.n; ++i){
                mp[i] = -1;
            }
            int cur = 0;
            for(int i = 0; i < g.n; ++i){
                int p = dsu.get_par(i);
                if(mp[p] == -1){
                    mp[p] = cur;
                    ++cur;
                }
                mp[i] = mp[p];
            }
            res = Graph(dsu.size());
            for(Edge e : g.edges){
                if(f.isBridge[e.id]){
                    int u = e.u;
                    int v = e.v;
                    u = mp[u];
                    v = mp[v];
                    res.add(u, v);
                }
            }
        }
        Graph get_graph(){
            return res;
        }
};
Graph g;
vector<bool> vis;
vector<tuple<int, int, int>> edges;
void dfs(int u){
    for(Edge e : g.adj[u]){
        if(!vis[e.id]){
            vis[e.id] = true;
            edges.push_back({e.id, e.u, e.v});
            dfs(e.v);
        }
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    g = Graph(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g.add(u, v);
    }
    BCC b(g);
    map<int, int> sz;
    for(int i = 0; i < n; ++i){
        ++sz[b.mp[i]];
    }
    int mx = 0, leader;
    for(auto [u, f] : sz){
        if(f > mx){
            mx = f;
            leader = u;
        }
    }
    int root;
    for(int i = 0; i < n; ++i){
        if(b.mp[i] == leader){
            root = i;
            break;
        }
    }
    vis = vector<bool>(m);
    dfs(root);

    cout << sz[leader] << '\n';
    sort(edges.begin(), edges.end());
    for(auto [id, u, v] : edges){
        swap(u, v);
        cout << (u + 1) << ' ' << (v + 1) << '\n';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
