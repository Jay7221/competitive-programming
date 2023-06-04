class CutPoints{
    public:
        Graph g;
        vector<int> tin, low;
        vector<bool> isCutPoint, vis;
        int timer;
        CutPoints(){
        }
        void dfs(int u, int id = -1){
            vis[u] = true;
            tin[u] = low[u] = timer;
            ++timer;
            bool hasChild = false;
            for(Edge e : g.adj[u]){
                if(e.id == id){
                    continue;
                }

                if(vis[e.v]){
                    low[u] = min(low[u], tin[e.v]);
                }
                else{
                    dfs(e.v, e.id);
                    low[u] = min(low[u], low[e.v]);

                    if(id == -1){
                        if(hasChild){
                            isCutPoint[u] = true;
                        }
                        hasChild = true;
                    }else{
                        if(tin[u] <= low[e.v]){
                            isCutPoint[u] = true;
                        }
                    }
                }
            }
        }
        CutPoints(Graph g){
            this -> g = g;
            int n = g.n;
            tin = vector<int>(n);
            low = vector<int>(n);
            isCutPoint = vector<bool>(n);
            vis = vector<bool>(n);
            timer = 0;
            dfs(0);
            for(int i = 0; i < n; ++i){
                cerr << i << " : " << tin[i] << ' ' << low[i] << '\n';
            }
        }
};

