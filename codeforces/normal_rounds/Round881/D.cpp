#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> graph;
vector<int> dp;
void dfs(int u, int p){
    for(int v : graph[u]){
        if(v != p){
            dfs(v, u);
            dp[u] += dp[v];
        }
    }
}
void solve(){
    int n;
    cin >> n;
    graph.assign(n, vector<int>());
    dp.assign(n, 0ll);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i < n; ++i){
        if(graph[i].size() == 1){
            dp[i] = 1;
        }
    }
    dfs(0, -1);
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << (dp[a] * 1ll * dp[b]) << '\n';
    }

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
