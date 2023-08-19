#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll LOGMAX = 23;
vector<vector<int>> graph;
vector<vector<int>> par;
vector<int> depth;
int getAnc(int u, int k){
    for(int i = 0; i < LOGMAX; ++i){
        if((1 << i) & k){
            u = par[u][i];
        }
    }
    return u;
}
int lca(int u, int v){
    if(depth[u] < depth[v]){
        swap(u, v);
    }
    u = getAnc(u, depth[u] - depth[v]);
    if(u == v){
        return u;
    }
    for(int i = LOGMAX - 1; i >= 0; --i){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    u = par[u][0];
    return u;
}
int dist(int u, int v){
    int ans = 0;
    if(depth[u] < depth[v]){
        swap(u, v);
    }
    ans += depth[u] - depth[v];
    u = getAnc(u, depth[u] - depth[v]);
    if(u == v){
        return ans;
    }
    for(int i = LOGMAX - 1; i >= 0; --i){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
            ans += pow(2, i + 1);
        }
    }
    ans += 2;
    return ans;
}
void dfs(int u, int p){
    par[u][0] = p;
    for(int v : graph[u]){
        if(v != p){
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}
void query(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int lc = a[0];
    for(int i = 0; i < n; ++i){
        lc = lca(lc, a[i]);
    }
    int mx = a[0];
    for(int i = 1; i < n; ++i){
        if(dist(mx, lc) < dist(a[i], lc)){
            mx = a[i];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
    	if(a[i] != mx){
    		ans = max(ans, dist(a[i], mx));
    	}
    }
    ans = (ans + 1) / 2;
    cout << ans << '\n';
}
void solve(){
    int n, q;
    cin >> n >> q;
    graph.assign(n + 1, vector<int>());
    par.assign(n + 1, vector<int>(LOGMAX));
    depth.assign(n + 1, 0);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    for(int k = 1; k < LOGMAX; ++k){
        for(int u = 1; u <= n; ++u){
            par[u][k] = par[par[u][k - 1]][k - 1];
        }
    }
    for(int i = 0; i < q; ++i){
        query();
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
