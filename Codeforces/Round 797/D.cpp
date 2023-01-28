#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> dp(n);
	for(int i = 0; i < n; ++i){
		char c;
		cin >> c;
		dp[i] = (c == 'W');
	}
	for(int i = 1; i < n; ++i){
		dp[i] += dp[i - 1];
	}
	int ans = dp[k - 1];
	for(int i = k; i < n; ++i){
		ans = min(ans, dp[i] - dp[i - k]);
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
}