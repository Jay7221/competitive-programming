#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<vector<ll> > dp(n, vector<ll>(2));
	// dp[i][0] = max value without adding x to a[i]
	// dp[i][1] = max value adding x to a[i]
	for(int i = 1; i < n; ++i){
		ll val1 = a[i] ^ a[i - 1], val2 = a[i] ^ (a[i - 1] + x);
		dp[i][0] = max(dp[i - 1][0] + val1, dp[i - 1][1] + val2);
		val1 = (a[i] + x) ^ a[i - 1], val2 = (a[i] + x) ^ (a[i - 1] + x);
		dp[i][1] = max(dp[i - 1][0] + val1, dp[i - 1][1] + val2);
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}