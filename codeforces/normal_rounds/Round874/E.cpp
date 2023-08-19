#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> graph;
vector<bool> vis;
bool isCycle;
int len;
void dfs(int u, int p = -1){
    vis[u] = true;
    for(int v : graph[u]){
        if(v != p){
            if(vis[v]){
                isCycle = true;
            }else{
                dfs(v, u);
            }
        }
    }
}
void solve(){
    int n;
    cin >> n;
    graph.assign(n, vector<int>());
    vis.assign(n, false);
    set<pair<int, int>> edges;
    for(int i = 0; i < n; ++i){
        int u = i;
        int v;
        cin >> v;
        --v;
        if(u > v){
            swap(u, v);
        }
        edges.insert({u, v});
    }
    for(auto [u, v] : edges){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int mn = 0, mx = 0;
    bool flag = true;
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            len = 0;
            isCycle = 0;
            dfs(i);
            if(isCycle){
            	++mn;
            	++mx;
            }else{
            	if(flag){
            		++mn;
            		++mx;
	            	flag = false;
            	}else{
            		++mx;
            	}
            }
        }
    }
    cout << mn << ' ' << mx << '\n';
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
