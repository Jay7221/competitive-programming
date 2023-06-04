#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
            n = m = 0;
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
class LCA{
    public:
        const int LOGMAX = 30;
        Graph g;
        vector<vector<int>> par;
        vector<int> depth;
        void dfs(int u, int p){
            par[u][0] = p;
            for(Edge e : g.adj[u]){
                if(e.v != p){
                    depth[e.v] = depth[e.u] + 1;
                    dfs(e.v, e.u);
                }
            }
        }
        LCA(){
        }
        LCA(Graph g){
            this -> g = g;
            par = vector<vector<int>>(g.n, vector<int>(LOGMAX, -1));
            depth = vector<int>(g.n);
            dfs(0, -1);
            for(int k = 1; k < LOGMAX; ++k){
                for(int i = 0; i < g.n; ++i){
                    if(par[i][k - 1] != -1){
                        par[i][k] = par[par[i][k - 1]][k - 1];
                    }
                }
            }
        }
        int get_lca(int u, int v){
            if(depth[u] > depth[v]){
                swap(u, v);
            }
            int k = depth[v] - depth[u];
            for(int i = 0; i < LOGMAX; ++i){
                if((k >> i) & 1){
                    v = par[v][i];
                }
            }
            if(u == v){
                return u;
            }
            for(int i = LOGMAX - 1; i >= 0; --i){
                if(par[u][i] != par[v][i]){
                    u = par[u][i];
                    v = par[v][i];
                }
            }
            u = par[u][0];
            v = par[v][0];
            return u;
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
vector<int> ss, dd, pp;
vector<int> com;
vector<bool> vis;
int cur = 0;
Graph g;
bool flag = true;
void dfs(int u, int id = -1){
    for(Edge e : g.adj[u]){
        if(e.id != id){
            dfs(e.v, e.id);
            ss[e.u] += ss[e.v];
            dd[e.u] += dd[e.v];
            pp[e.u] += pp[e.v];
        }
    }
    if((ss[u] > pp[u]) && (dd[u] > pp[u])){
        flag = false;
    }
}
void dfs1(int u){
    vis[u] = true;
    com[u] = cur;
    for(Edge e : g.adj[u]){
        if(!vis[e.v]){
            dfs1(e.v);
        }
    }
}
void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    ss = vector<int>(n);
    dd = vector<int>(n);
    pp = vector<int>(n);
    com = vector<int>(n);
    vis = vector<bool>(n);
    g = Graph(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g.add(u, v);
    }
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            dfs1(i);
            ++cur;
        }
    }
    BCC b(g);
    g = b.res;

    n = g.n;
    m = g.m;
    LCA l(g);
    vector<pair<int, int>> queries;
    for(int i = 0; i < q; ++i){
        int s, d;
        cin >> s >> d;
        --s, --d;
        queries.push_back({s, d});
    }
    for(auto [s, d] : queries){
        if(com[s] != com[d]){
            flag = false;
            break;
        }
        s = b.mp[s];
        d = b.mp[d];
        if(s != d){
            int p = l.get_lca(s, d);
            ++ss[s];
            ++dd[d];
            ++pp[p];
        }
    }
    dfs(0, -1);
    if(flag){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

	return 0;
}
