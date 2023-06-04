#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	auto debug = [&](vector<ll>& a){
		for(auto c : a)
			cerr << c << ' ';
		cerr << '\n';
	};
	int n;
	cin >> n;
	vector<ll> a(n + 1), dp(n + 1);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(ll i = 1; i <= n; ++i)
		dp[i] = min(dp[i - 1] + 1, a[i]);
	ll ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += dp[i];
	}
	cout << ans << '\n';
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
	return 0;
}