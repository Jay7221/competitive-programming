#include<bits/stdc++.h>
using namespace std;
#define ll long long

class DSU{
    public:
        vector<int> par;
        vector<int> rank;
        int n;
        DSU(){
            n = 0;
        }
        DSU(int n){
            this -> n = n;
            par = vector<int>(n);
            for(int i = 0; i < n; ++i){
                par[i] = i;
            }
            rank = vector<int>(n, 1);
        }
        int get_par(int u){
            if(par[u] == u){
                return u;
            }
            return par[u] = get_par(par[u]);
        }
        void merge(int u, int v){
            u = get_par(u);
            v = get_par(v);
            if(u == v){
                return;
            }
            if(rank[u] < rank[v]){
                swap(u, v);
            }
            par[v] = u;
            rank[u] += rank[v];
            --n;
        }
        int size(){
            return n;
        }
};

void solve(){
    int n;
    cin >> n;
    vector<tuple<int, int, int>> edges;
    for(int i = 1; i <= n; ++i){
        int w;
        cin >> w;
        edges.push_back({w, 1, i});
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    DSU dsu(n + 1);
    sort(edges.begin(), edges.end());
    ll cost = 0;
    for(auto [w, u, v]: edges){
        if(dsu.get_par(u) != dsu.get_par(v)){
            cost += w;
            dsu.merge(u, v);
        }
    }
    cout << cost << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
