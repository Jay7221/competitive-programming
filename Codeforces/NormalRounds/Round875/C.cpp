#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<int, int>>> graph;
int ans;
void dfs(int u, int numInv, int cur, int p = -1){
    ans = max(ans, numInv);
    for(auto [v, w] : graph[u]){
        if(v == p){
            continue;
        }
        if(w < cur){
            dfs(v, numInv + 1, w, u);
        }else{
            dfs(v, numInv, w, u);
        }
    }
}
void solve(){
    int n;
    cin >> n;
    graph.assign(n, vector<pair<int, int>>());
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }
    ans = 1;
    dfs(0, 1, 0);
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
