#include<bits/stdc++.h>
using namespace std;

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
        int N, M;
        vector<vector<Edge>> adj;
        Graph(){
        }
        Graph(int N){
            M = 0;
            this -> N = N;
            adj = vector<vector<Edge>>(N, vector<Edge>());
        }
        void add(int i, int j){
            adj[i].push_back(Edge(i, j, M));
            adj[j].push_back(Edge(j, i, M));
            ++M;
        }
};

Graph g;
vector<int> pre, low;
vector<int> bridges;
vector<bool> art;
int cnt = 0;
void dfs(int u, int p, int id){
    pre[u] = cnt;
    low[u] = pre[u];
    ++cnt;
    bool hasFwd = false;
    for(Edge e : g.adj[u]){
        if(e.id == id){
            continue;
        }

        if(pre[e.v] == -1){
            dfs(e.v, u, e.id);
            low[u] = min(low[u], low[e.v]);

            if(low[e.v] == pre[e.v]){
                bridges.push_back(e.id);
            }

            if(u != p ? low[e.v] >= pre[u] : hasFwd){
                art[u] = true;
            }

            hasFwd = true;
        }
        else{
            low[u] = min(low[u], pre[e.v]);
        }
    }
 //   cerr << u + 1 << ' ' << pre[u] + 1 << ' ' << low[u] + 1 << '\n';
}
int main(){
    int n, m;
    cin >> n >> m;
    g = Graph(n);
    pre = vector<int>(n, -1);
    low = vector<int>(n);
    art = vector<bool>(n);
    for(int i = 0; i < m; ++i){
        int u,v ;
        cin >> u >> v;
        --u, --v;
        g.add(u, v);
    }
    for(int i = 0; i < g.N; ++i){
        if(pre[i] == -1){
            dfs(i, i, g.M);
        }
    }
    for(int i = 0; i < n; ++i){
        if(art[i]){
            cerr << i + 1 << ' ';
        }
    }
    cerr << '\n';
    for(int b : bridges){
        cerr << b + 1 << ' ' ;
    }
    cerr << '\n';
}
