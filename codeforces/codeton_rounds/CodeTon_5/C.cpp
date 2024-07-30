#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    vector<int> dp(n + 1), mx(n + 1);
    vector<bool> vis(n + 1);

    for(int i = 1; i <= n; ++i){
        dp[i] = dp[i - 1];
        if(vis[a[i]]){
            dp[i] = max(dp[i], i + 1 + mx[a[i]]);
            mx[a[i]] = max(mx[a[i]], dp[i - 1] - i);
        }
        else{
            vis[a[i]] = true;
            mx[a[i]] = dp[i - 1] - i;
        }
    }

    cout << dp[n] << '\n';
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
