#include<bits/stdc++.h>
using namespace std;
void solve(){
    int INF = 1e9 + 7;
    int M, R, n;
    cin >> M >> R >> n;
    vector<int> v(n), dp(n, INF);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    auto get = [&](int x){
        if(x <= 0){
            return 0;
        }
        int l = 0, r = n - 1;
        if(x > v[r] + R){
            return INF;
        }
        while(l < r){
            int m = (l + r) / 2;
            if(v[m] + R < x){
                l = m + 1;
            }else{
                r = m;
            }
        }
        return dp[l];
    };
    for(int i = 0; i < n; ++i){
        dp[i] = min(dp[i], 1 + get(max(0, v[i] - R)));
    }
    int ans = get(M);
    if(ans == INF){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << ans << '\n';
    }
}
int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
