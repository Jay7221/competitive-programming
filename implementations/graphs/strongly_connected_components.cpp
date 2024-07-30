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

