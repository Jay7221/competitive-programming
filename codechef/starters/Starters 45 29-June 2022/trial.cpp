#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (ll)(1e9 + 7)
int main(){
    // freopen("inputf.in","r",stdin);
    // freopen("outputf.out","w",stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<ll> > dist(n, vector<ll>(n, -inf));
    for(int i = 0; i < m; ++i){
        int u, v, x;
        cin >> u >> v >> x;
        --u, --v;
        dist[u][v] = x;
    }
    for(int i = 0; i < n; ++i){
        dist[i][i] = 0;
    }
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n ;++i){
            for(int j = 0; j < n; ++j){
                if(dist[i][k] > -inf && dist[k][j] > -inf){
                    if(dist[i][j] < dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    if(dist[0][n - 1] > -inf && dist[n - 1][0] > -inf){
        if(dist[0][n - 1] + dist[n -1][0] > 0){
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << dist[0][n - 1] << '\n';
}