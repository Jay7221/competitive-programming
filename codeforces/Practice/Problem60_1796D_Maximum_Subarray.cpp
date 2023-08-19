#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
void debug(vector<ll> &v){
    for(ll elem : v){
        cerr << elem << ' ';
    }
    cerr << '\n';
}
void debug(vector<vector<ll>> &v){
    for(vector<ll> vv : v){
        debug(vv);
    }
    cerr << "-----------------------\n";
}
void solve(){
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -INF));
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= min(k, i); ++j){
            if(i - 1 >= j){
                dp[i][j] = max(dp[i][j], (a[i] - x) + max(0ll, dp[i - 1][j]));
            }
            if(j > 0){
                dp[i][j] = max(dp[i][j], (a[i] + x) + max(0ll, dp[i - 1][j - 1]));
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = max(0, i + k - n); j <= min(i, k); ++j){
            ans = max(ans, dp[i][j]);
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
