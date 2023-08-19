#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int j, id;
        Edge(int j, int id){
            this -> j = j;
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
            adj[i].push_back(Edge(j, M));
            adj[j].push_back(Edge(i, M));
            ++M;
        }
};

Graph g;
vector<int> pre, low;
vector<int> bridges;
vector<bool> art, used;
stack<int> st;
vector<vector<int>> components;
int cnt = 0;

vector<int> makeComponent(int id){
    vector<int> component;
    while(st.top() != id){
        component.push_back(st.top());
        st.pop();
    }
    if(st.top() != g.M){
        component.push_back(st.top());
    }
    st.pop();
    return component;
}
int dfs(int i, int p, int id){
    if(!used[id]){
        st.push(id);
        used[id] = true;
    }
   if(pre[i] != -1){
       low[p] = min(low[p], pre[i]);
       return low[p];
   }
   pre[i] = cnt++;
   low[i] = pre[i];
   bool hasFwd = false;

   for(Edge e : g.adj[i]){
       if(e.id == id){
           continue;
       }
       if(dfs(e.j, i, e.id) < 0){
           low[i] = min(low[i], low[e.j]);
           if(low[e.j] == pre[e.j]){
               bridges.push_back(e.id);
           }

           if(i != p ? low[e.j] >= pre[i] : hasFwd){
               art[i] = true;
               components.push_back(makeComponent(e.id));
           }

           hasFwd = true;
       }
   }
   return -1;
}
int main(){
    int n, m;
    cin >> n >> m;
    g = Graph(n);
    pre = vector<int>(n, -1);
    low = vector<int>(n);
    art = vector<bool>(n);
    used = vector<bool>(m);
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
    components.push_back(makeComponent(g.M));
    for(vector<int> com : components){
        for(int u : com){
            ++u;
            cerr << u << ' ' ;
        }
        cerr << '\n';
    }
}
