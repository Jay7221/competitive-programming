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

