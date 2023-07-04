#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, q;
    cin >> n >> q;
    const int LOGMAX = 30;
    vector<vector<int>> par(n, vector<int>(LOGMAX, -1));
    vector<int> depth(n, -1);
    for(int i = 1; i < n; ++i){
        cin >> par[i][0];
        --par[i][0];
    }
    for(int i = 0; i < n; ++i){
        for(int k = 1; k < LOGMAX; ++k){
            if(par[i][k - 1] != -1){
                par[i][k] = par[par[i][k - 1]][k - 1];
            }
        }
    }
    depth[0] = 0;
    auto dfs = [&](int u, auto &self) -> void{
        if(depth[par[u][0]] == -1){
            self(par[u][0], self);
        }
        depth[u] = depth[par[u][0]] + 1;
    };
    for(int i = 1; i < n; ++i){
        dfs(i, dfs);
    }

    auto query = [&](int u, int v){
        if(depth[u] > depth[v]){
            swap(u, v);
        }
        for(int k = LOGMAX - 1; k >= 0; --k){
            if((1 << k) & (depth[v] - depth[u])){
                v = par[v][k];
            }
        }
        if(u == v){
            return u;
        }
        for(int k = LOGMAX - 1; k >= 0; --k){
            if(par[u][k] != par[v][k]){
                u = par[u][k];
                v = par[v][k];
            }
        }
        return par[u][0];
    };

    while(q--){
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << (query(a, b) + 1) << '\n';
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
