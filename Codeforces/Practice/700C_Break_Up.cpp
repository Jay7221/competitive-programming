#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e12 + 7;
int gid = -1;
class Edge{
    public:
        int u, v, id;
        ll weight;
        Edge(int u, int v, int weight, int id){
            this -> u = u;
            this -> v = v;
            this -> id = id;
            this -> weight = weight;
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
        void add(int u, int v, int w){
            adj[u].push_back(Edge(u, v, w, m));
            adj[v].push_back(Edge(v, u, w, m));
            edges.push_back(Edge(u, v, w, m));
            ++m;
        }
};
int s, t;
int ignore_id, timer;
Graph g;
vector<bool> vis;
vector<int> path;
vector<int> par, par_edge, par_weight;
vector<int> tin, low;

bool dfs(int u){
    vis[u] = true;
    if(u == t){
        return true;
    }
    for(Edge e : g.adj[u]){
        if(!vis[e.v]){
            path.push_back(e.id);
            if(dfs(e.v)){
                return true;
            }
            path.pop_back();
        }
    }
    return false;
}

void dfs_1(int u, int id = -1){
    tin[u] = low[u] = timer;
    ++timer;
    vis[u] = true;

    for(Edge e : g.adj[u]){
        if((e.id == id) || (e.id == ignore_id)){
            // this edge is to be ignored or is a parent edge from where we came
            continue;
        }
        if(vis[e.v]){
            // this is back-edge
            low[u] = min(low[u], tin[e.v]);
        }
        else{
            // this is a forward edge or a tree edge
            dfs_1(e.v, e.id);
            low[u] = min(low[u], low[e.v]);
            par[e.v] = u;
            par_edge[e.v] = e.id;
            par_weight[e.v] = e.weight;
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    cin >> s >> t;
    --s, --t;
    g = Graph(n);
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g.add(u, v, w);
    }
    vis = vector<bool>(n);
    if(!dfs(s)){
        // There is no path from s to t, so no need to remove any edges
        cout << 0 << ' ' << 0 << '\n';
        return;
    }

    // There is atleast one path from s to t, some edges need to be reomved
    vector<int> removal_edges;
    ll ans = INF;
    for(int id : path){
        Edge cur_edge = g.edges[id];
        ignore_id = id;
        timer = 0;
        tin = vector<int>(n);
        low = vector<int>(n);
        vis = vector<bool>(n);
        par = vector<int>(n, -1);
        par_edge = vector<int>(n);
        par_weight = vector<int>(n);

        dfs_1(s);

        if(par[t] == -1){
            if(ans > cur_edge.weight){
                ans = cur_edge.weight;
                removal_edges.clear();
                removal_edges.push_back(cur_edge.id);
            }
        }else{
            int cur_node = t;
            while(cur_node != s){
                if(tin[par[cur_node]] < low[cur_node]){
                    // the edge joining cur_node and par[cur_node] is a bridge
                    if(ans > cur_edge.weight + par_weight[cur_node]){
                        ans = cur_edge.weight + par_weight[cur_node];
                        removal_edges.clear();
                        removal_edges.push_back(cur_edge.id);
                        removal_edges.push_back(par_edge[cur_node]);
                    }
                }
                cur_node = par[cur_node];
            }
        }
    }
    if(ans == INF){
        cout << -1 << '\n';
    }else{
        cout << ans << '\n';
        cout << removal_edges.size() << '\n';
        for(int id : removal_edges){
            cout << (id  + 1) << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
