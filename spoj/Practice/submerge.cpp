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
        }
};
bool solve(){
    int n, m;
    cin >> n >> m;
    if((n == 0) && (m == 0)){
        return false;
    }

    Graph g(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g.add(u, v);
    }
    CutPoints c(g);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans += c.isCutPoint[i];
    }
    cout << ans << '\n';
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(solve()){
        continue;
    }

    return 0;
}
