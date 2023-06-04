class Decompose{
    public:
        vector<int> component;
        vector<bool> vis;
        int cur;
        Graph g;
        void dfs(int u, int id = -1){
            vis[u] = true;
            component[u] = cur;
            for(Edge e : g.adj[u]){
                if(!vis[e.v]){
                    dfs(e.v);
                }
            }
        }
        Decompose(){
        }
        Decompose(Graph g){
            this -> g = g;
            component = vector<int>(g.n);
            vis = vector<bool>(g.n);
            cur = 0;
            for(int i = 0; i < g.n; ++i){
                if(!vis[i]){
                    dfs(i);
                    cerr << '\n';
                    ++cur;
                }
            }
        }
};

