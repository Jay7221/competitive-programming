#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ; } cerr << '\n';
void solve(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector<int> va(n), vb(n);
	for(int i = 0; i < n; ++i){
		va[i] = (b[i] - a[i] + 26) % 26;
		vb[i] = (a[i] - b[i] + 26) % 26;
	}
	vector<bitset<2 * 26 + 1> > dp(n + 1);
	dp[0][26] = 1;
	for(int i = 0; i < n; ++i){
		dp[i + 1] = (dp[i + 1] | (dp[i] >> va[i]));
		dp[i + 1] = (dp[i + 1] | (dp[i] << vb[i]));
	}
	int ans = 26;
	for(int i = 0; i < 2 * 26 + 1; ++i){
		if(dp[n][i]){
			ans = min(ans, abs(i - 26));
		}
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