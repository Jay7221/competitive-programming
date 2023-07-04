#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(k), d(k);
    for(int i = 0; i < k; ++i){
        cin >> x[i];
        --x[i];
    }
    for(int i = 0; i < k; ++i){
        cin >> d[i];
    }
    vector<int> dp(n);
    for(int i = 0; i < k; ++i){
        dp[x[i]] = max(dp[x[i]], d[i]);
    }
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; ++i){
        pq.push({dp[i], i});
    }
    while(pq.size()){
        int val, ind;
        tie(val, ind) = pq.top();
        pq.pop();
        if(val < dp[ind]){
            continue;
        }
        for(int v : graph[ind]){
            if(dp[v] < dp[ind] - 1){
                dp[v] = dp[ind] - 1;
                pq.push({dp[v], v});
            }
        }
    }

    bool flag = true;
    for(int i = 0; i < n; ++i){
        if(dp[i] == 0){
            flag = false;
        }
    }
    if(flag){
        cout << "YES\n";
    }else{
        cout << "NO\n";
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
