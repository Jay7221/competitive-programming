#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> dp(n, 0);
    for(int i = 0; i < k; ++i){
        int p, h;
        cin >> p >> h;
        --p;
        dp[p] = h + 1;
    }
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; ++i){
        pq.push({dp[i], i});
    }
    while(pq.size()){
        int val, u;
        tie(val, u) = pq.top();
        pq.pop();
        if(val == 0){
            break;
        }
        if(dp[u] > val){
            continue;
        }
        for(int v : graph[u]){
            if(dp[v] < dp[u] - 1){
                dp[v] = dp[u] - 1;
                pq.push({dp[v], v});
            }
        }
    }

    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(dp[i] > 0){
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int elem : ans){
        cout << (elem + 1) << ' ';
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
