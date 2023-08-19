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

