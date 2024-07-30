#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> ans(n + 1);
    for(int root = 0; root < n; ++root){
        vector<int> depth(n);
        vector<bool> vis(n);
        queue<int> q;
        q.push(root);
        vis[root] = true;
        vector<int> tmp(n + 1);
        for(int k = 0; k <= n; ++k){
            tmp[k] = (n - 1) * k;
        }
        int cur = 1;
        int sum = 0;
        while(q.size()){
            int u = q.front();
            q.pop();
            for(int v : graph[u]){
                if(!vis[v]){
                    vis[v] = true;
                    depth[v] = depth[u] + 1;
                    ++cur;
                    sum += 2 * depth[v];
                    tmp[cur] -= sum;

                    q.push(v);
                }
            }
        }

        for(int k = 0; k <= n; ++k){
            ans[k] = max(ans[k], tmp[k]);
        }
    }
    for(int i = 0; i <= n; ++i){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
