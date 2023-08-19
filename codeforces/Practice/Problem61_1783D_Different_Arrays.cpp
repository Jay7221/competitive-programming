#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
const int MAX = 9e4;
ll add(ll a, ll b){
    return ((a + b) % MOD);
}
ll sub(ll a, ll b){
    return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
    return ((a * b) % MOD);
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> dp(n, vector<int>(2 * MAX));
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    dp[1][MAX + a[1]] = 1;
    for(int i = 1; i < n - 1; ++i){
        for(int j = -(MAX - 1); j < MAX; ++j){
            int cur = MAX + j;
            if(dp[i][cur] > 0){
                int next = MAX + (a[i + 1] + j);
                dp[i + 1][next] = add(dp[i + 1][next], dp[i][cur]);
                if(j != 0){
                    next = MAX + (a[i + 1] - j);
                    dp[i + 1][next] = add(dp[i + 1][next], dp[i][cur]);
                }
            }
        }
    }
    ll ans = 0;
    for(int j = -(MAX - 1); j < MAX; ++j){
        int cur = j + MAX;
        ans = add(ans, dp[n - 1][cur]);
    }
    cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  
  solve();

	return 0;
}
