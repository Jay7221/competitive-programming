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

    auto query = [&](int u, int h){
        h = min(h, depth[u] + 1);
        for(int k = 0; k < LOGMAX; ++k){
            if((h >> k) & 1){
                u = par[u][k];
            }
        }
        return u;
    };

    while(q--){
        int x, k;
        cin >> x >> k;
        --x;
        int res = query(x, k);
        res += (res != -1);
        cout << res << '\n';
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
