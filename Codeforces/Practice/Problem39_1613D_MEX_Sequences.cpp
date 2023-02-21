#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
ll add(ll a, ll b){
	return ((a + b) % MOD);
}
ll mult(ll a, ll b){
	return ((a * b) % MOD);
}
void solve(){
	int n;
	cin >> n;
	ll dp[n + 2][2];
	for(int i = 0; i <= n + 1; ++i){
		for(int k = 0; k < 2; ++k){
			dp[i][k] = 0;
		}
	}
	ll a[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		ll x = a[i];
		if(x > 0){
			dp[x - 1][1] = add(dp[x - 1][1], add(dp[x - 1][1], dp[x - 1][0]));
		}
		dp[x + 1][0] = add(dp[x + 1][0], add(dp[x + 1][0], dp[x][0]));
		dp[x + 1][1] = add(dp[x + 1][1], dp[x + 1][1]);
		if(a[i] == 0){
			dp[1][0] = add(1, dp[1][0]);
		}
		if(a[i] == 1){
			dp[0][1] = add(1, dp[0][1]);
		}
	}
	ll ans = 0;
	for(int i = 0; i <= n + 1; ++i){
		for(int k = 0; k < 2; ++k){
			ans = add(ans, dp[i][k]);
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
