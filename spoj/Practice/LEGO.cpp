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
    vector<tuple<int, int, int, int>> v(n);
    map<int, vector<tuple<int, int, int>>> xa, xb;
    for(int i = 0; i < n; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v[i] = {x1, y1, x2, y2};
        xa[y1].push_back({x2, x1, i});
        xb[y2].push_back({x2, x1, i});
    }
    DSU d(n);
    int i = 0;
    for(auto [x1, y1, x2, y2] : v){
        tuple<int, int, int> t = {x1, 0, 0};
        auto k1 = upper_bound(xb[y1].begin(), xb[y1].end(), t);
        auto k2 = upper_bound(xa[y2].begin(), xa[y2].end(), t);
        if(k1 != xb[y1].end()){
            int a, b, ind;
            tie(a, b, ind) = *k1;
            if(b <= x1){
                d.merge(i, ind);
            }
        }
        if(k2 != xa[y2].end()){
            int a, b, ind;
            tie(a, b, ind) = *k2;
            if(b <= x1){
                d.merge(i, ind);
            }
        }
        ++i;
    }
    cout << d.size() << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
