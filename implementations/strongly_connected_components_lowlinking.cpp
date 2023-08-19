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
            edges.push_back(Edge(u, v, m));
            ++m;
        }
};

class Tarjan{
    public:
        Graph g, g_cond;
        vector<int> pre, low, id;
        stack<int> stk;
        int preorderCounter;
        int numSCCs;

        Tarjan(){
        }
        Tarjan(Graph g){
            this -> g = g;
            pre = vector<int>(g.n, -1);
            low = vector<int>(g.n);
            id = vector<int>(g.n);
            preorderCounter = 0;

            for(int i = 0; i < g.n; ++i){
                if(pre[i] == -1){
                    dfs(i);
                }
            }
        }

        void dfs(int u){
            pre[u] = preorderCounter++;
            low[u] = pre[u];
            stk.push(u);

            for(Edge e : g.adj[u]){
                if(pre[e.v] == -1){
                    dfs(e.v);
                }
                low[u] = min(low[u], low[e.v]);
            }

            if(low[u] == pre[u]){
                // u is the root of a SCC
                while(true){
                    int v = stk.top();
                    stk.pop();
                    id[v] = numSCCs;
                    low[v] = g.n;

                    if(v == u){
                        break;
                    }
                }

                ++numSCCs;
            }
        }

        Graph get_condensed(){
            set<pair<int, int>> edges;
            for(Edge e : g.edges){
                edges.insert({e.u, e.v});
            }
            for(auto [u, v] : edges){
                g_cond.add(u, v);
            }
            return g_cond;
        }
};


void solve(){
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g.add(u, v);
    }
    Tarjan t(g);
    for(int i = 0; i < n; ++i){
        cout << (i + 1) << " : " << (t.id[i] + 1) << '\n';
    }
    cout << "------------------------\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve();
	}
}
