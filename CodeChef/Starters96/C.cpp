#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18 + 7;
void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> graph(n);
    vector<vector<ll>> d(n, vector<ll>(n, INF));

    vector<ll> a(n);
    vector<bool> isGiven(n);

    for(int i = 0; i < m; ++i){
        int pos, val;
        cin >> pos >> val;
        --pos;
        a[pos] = val;
        isGiven[pos] = true;
    }
    for(int i = 0; i < k; ++i){
        int u, v, d;
        cin >> u >> v >> d;
        --u, --v;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    for(int node = 0; node < n; ++node){
        if(!isGiven[node]){
            continue;
        }

        priority_queue<pair<ll, int>> pq;

        pq.push({0, node});
        d[node][node] = 0;

        vector<bool> vis(n);

        while(pq.size()){
            int u;
            ll dist;
            tie(dist, u) = pq.top();
            dist = -dist;
            pq.pop();
            if(vis[u]){
                continue;
            }
            vis[u] = true;
            for(auto [v, w] : graph[u]){
                if(d[node][v] > (w + dist)){
                    d[node][v] = w + dist;
                    pq.push({-(w + dist), v});
                }
            }
        }
    }

    bool flag = true;

    for(int u = 0; u < n; ++u){
        for(int v = u + 1; v < n; ++v){
            if(isGiven[u] && isGiven[v]){
                flag &= (abs(a[u] - a[v]) <= d[u][v]);
            }
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
