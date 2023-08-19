#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	ll x;
	cin >> n >> x;
	vector<ll> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<vector<ll> > dp(n, vector<ll>(n + 1, 0));
	dp[0][0] = max(a[0], 0ll);
	for(int i = 1; i < n + 1; i++)
		dp[0][i] = max(0ll, a[0] + x);
	for(int i = 1; i < n; i++){
		dp[i][0] = max(a[i], dp[i - 1][0] + a[i]);
		dp[i][0] = max(dp[i][0], 0ll);
		for(int k = 1; k < n + 1; k++){
			dp[i][k] = max(dp[i - 1][k] + a[i], dp[i - 1][k - 1] + a[i] + x);
			dp[i][k] = max(dp[i][k], dp[i][k - 1]);
		}
	}
	vector<ll> ans(n + 1);
	for(int k = 0; k < n + 1; k++){
		for(int i = 0; i < n; i++){
			ans[k] = max(ans[k], dp[i][k]);
		}
		cout << ans[k] << ' ' ;
	}
	cout << '\n';
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