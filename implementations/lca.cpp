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
class LCA_g{
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

