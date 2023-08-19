#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
void solve(){
    int n, m;
    cin >> n >> m;
    int r;
    cin >> r;
    bool dp[n + 1][m + 1][r + 1], isShot[n + 1][m + 1][r + 1];
    // dp[i][j][k] = can player be at point (i, j) at the end of time (i + j + k)
    // isShot[i][j][k] = is the point (i, j) shot at the end of time (i + j + k)
    // if there were k pauses and you are at point (i, j), then it took exactly (i + j + k) seconds to reach there
    // There can be at most r pauses in an optimal solution

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            for(int k = 0; k <= r; ++k){
                dp[i][j][k] = isShot[i][j][k] = false;
            }
        }
    }
    for(int i = 0; i < r; ++i){
        int t, d, coord;
        cin >> t >> d >> coord;
        if(d == 1){
            // horizontal shot
            for(int j = 0; j <= min(m, (t - coord)); ++j){
                if((t - coord - j) <= r){
                    isShot[coord][j][t - (coord + j)] = true;
                }
            }
        }else{
            // vertical shot
            for(int i = 0; i <= min(n, (t - coord)); ++i){
                if((t - coord - i) <= r){
                    isShot[i][coord][t - (coord + i)] = true;
                }
            }
        }
    }
    dp[0][0][0] = true;

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            for(int k = 0; k <= r; ++k){
                if(isShot[i][j][k]){
                    continue;
                }
                if(i > 0){
                    dp[i][j][k] = (dp[i][j][k] | dp[i - 1][j][k]);
                }
                if(j > 0){
                    dp[i][j][k] = (dp[i][j][k] | dp[i][j - 1][k]);
                }
                if(k > 0){
                    dp[i][j][k] = (dp[i][j][k] | dp[i][j][k - 1]);
                }
            }
        }
    }
    int ans = -1;
    for(int k = 0; k <= r; ++k){
        if(dp[n][m][k]){
            ans = n + m + k;
            break;
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
