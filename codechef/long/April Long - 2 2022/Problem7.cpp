#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(998244353)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<vector<vector<ll> > > dp(n, vector<vector<ll> >(2, vector<ll>(2, 0)));
	dp[n - 1][0][0] = 1;
	dp[n - 1][1][1] = 1;
	for(int i = n - 2; i > -1; i--){
		bool prev = (a[i + 1] % 2);
		for(int k = 0; k < 2; k++){
			dp[i][k][k] += dp[i + 1][prev][k ^ 1];
			dp[i][k][0] += dp[i + 1][(prev + k) % 2][0];
			dp[i][k][1] += dp[i + 1][(prev + k) % 2][1];
			dp[i][k][k] %= mod;
			dp[i][k][0] %= mod;
			dp[i][k][1] %= mod;
		}
	}
	// for(int i = 0; i < n; i++){
	// 	cout << dp[i][0][0] << ' ' << dp[i][0][1] << ' ' << dp[i][1][0] << ' ' << dp[i][1][1] << '\n';
	// }
	cout << ((dp[0][a[0] % 2][0] + dp[0][a[0] % 2][1]) % mod) << '\n';
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
}