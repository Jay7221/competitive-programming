#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e15 + 7;
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	ll ans = 0;
	auto cost = [&](int i){
		ll ans = 0;
		if(a[i] <= max(a[i - 1], a[i + 1])){
			ans = max(a[i - 1], a[i + 1]) - a[i] + 1;
		}
		return ans;
	};
	if(n % 2){
		for(int i = 1; i < n - 1; i += 2){
			ans += cost(i);
		}
	}else{
		// for(int i = 2; i < n - 1; i += 2){
		// 	ans += cost(i);
		// }
		ans = inf;
		vector<vector<ll> > dp(n, vector<ll>(2, inf));
		dp[0][1] = 0;
		dp[1][0] = cost(1);
		for(int i = 2; i < n - 1; ++i){
			dp[i][0] = dp[i - 2][0] + cost(i);
			dp[i][1] = dp[i - 2][1] + cost(i);
			if(i > 2)
				dp[i][1] = min(dp[i][1], dp[i - 3][0] + cost(i));
		}
		ans = min(ans, dp[n - 2][1]);
		ans = min(ans, dp[n - 3][0]);
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}