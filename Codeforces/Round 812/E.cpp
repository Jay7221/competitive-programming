#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e3 + 7;
vector<int> par(MAX);
vector<vector<int> > a(MAX, vector<int>(MAX));
int getPar(int u){
    if(u < 0)
        return -getPar(-u);
    if(u == par[u])
        return u;
    return par[u] = getPar(par[u]);
}
void join(int u, int v){
    u = getPar(u);
    v = getPar(v);
    if(abs(u) != abs(v)){
        if(u > 0)
            par[u] = v;
        else
            par[-u] = -v;
    }
}
int n;
void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        par[i] = i;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(a[i][j] < a[j][i])
                join(i, j);
            if(a[i][j] > a[j][i])
                join(i, -j);
        }
    }
    for(int i = 1; i <= n; ++i){
        if(getPar(i) < 0)
            continue ;
        for(int j = 1; j <= n; ++j){
            swap(a[i][j], a[j][i]);
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << a[i][j] << ' ' ;
        }
        cout << '\n';
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}