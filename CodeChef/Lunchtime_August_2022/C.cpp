#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> map(n + 1, INF), dp(n + 1, INF);
	map[a[n - 1]] = 0;
	dp[n - 1] = 0;
	for(int i = n - 2; i > -1; --i){
		if(a[i] <= a[i + 1])
			dp[i] = dp[i + 1];
		dp[i] = min(dp[i], 1 + map[a[i]]);
		map[a[i]] = min(map[a[i]], dp[i]);
	}
	if(dp[0] == INF)
		cout << -1 << '\n';
	else
		cout << dp[0] << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}