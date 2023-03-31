#include<bits/stdc++.h>
using namespace std;
void solve(){
	const int INF = 1e9 + 7;
	int n, m;
	cin >> n >> m;
	int dp[n][m];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> dp[i][j];
		}
	}
	for(int i = 1; i < n; ++i){
		int mn = *min_element(dp[i - 1], dp[i - 1] + m);
		for(int j = 0; j < m; ++j){
			dp[i][j] += mn;
		}
	}
	int ans = *min_element(dp[n - 1], dp[n - 1] + m);
	if(ans == INF){
		ans = -1;
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}