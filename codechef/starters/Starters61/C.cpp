#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
const int MAX = 1e4 + 7;
const int INF = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	vector<int> r(n), b(n);
	for(int i = 0; i < n; ++i)
		cin >> r[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	vector<vector<int>> dp(n + 1, vector<int>(MAX, -INF));
	dp[0][0] = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < MAX; ++j){
			if(r[i] + j < MAX)
				dp[i + 1][r[i] + j] = max(dp[i + 1][r[i] + j], dp[i][j]);
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + b[i]);
		}
	}
	int ans = -INF;
	for(int j = 0; j < MAX; ++j)
		ans = max(ans, min(j, dp[n][j]));
	cout << ans << '\n';
}


int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
