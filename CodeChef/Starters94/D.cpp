#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
    int LOGMAX = 32;
    vector<int> sum(LOGMAX);
    vector<vector<int>> row(n, vector<int>(LOGMAX));
    vector<vector<int>> col(m, vector<int>(LOGMAX));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            for(int k = 0; k < LOGMAX; ++k){
                if((a[i][j] >> k) & 1){
                    ++sum[k];
                    ++col[j][k];
                    ++row[i][k];
                }
            }
        }
    }
    ll ans = 0;
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            ll cur = 0;
            for(int k = 0; k < LOGMAX; ++k){
                ll tmp;
                if((a[x][y] >> k) & 1){
                    tmp = (1ll << k) * ((n * m - sum[k]) - (n - col[y][k]) - (m - row[x][k]));
                }else{
                    tmp = (1ll << k) * (sum[k] - col[y][k] - row[x][k]);
                }
                cur += tmp;
            }
            ans = max(ans, cur);
        }
    }
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
