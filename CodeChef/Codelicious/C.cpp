#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
void solve(){
	int n;
	cin >> n;
	
	vector<vector<ll>> x(n), dp(n);
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		x[i].assign(k, 0);
		dp[i].assign(k, INF);
		for(int j = 0; j < k; ++j){
			cin >> x[i][j];
		}
		sort(x[i].begin(), x[i].end());
	}
	dp[0].assign(dp[0].size(), 0);
	for(int i = 1; i < n; ++i){
		int k = x[i].size();
		for(int j = 0; j < k; ++j){
			int r = lower_bound(x[i - 1].begin(), x[i - 1].end(), x[i][j]) - x[i - 1].begin();
			int l = upper_bound(x[i - 1].begin(), x[i - 1].end(), x[i][j]) - x[i - 1].begin() - 1;
			if(l >= 0){
				dp[i][j] = min(dp[i][j], dp[i - 1][l] + abs(x[i - 1][l] - x[i][j]));
			}
			if(r < x[i - 1].size()){
				dp[i][j] = min(dp[i][j], dp[i - 1][r] + abs(x[i - 1][r] - x[i][j]));
			}
		}
		for(int j = 1; j < k; ++j){
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + abs(x[i][j] - x[i][j - 1]));
		}
		for(int j = k - 2; j >= 0; --j){
			dp[i][j] = min(dp[i][j], dp[i][j  + 1] + abs(x[i][j] - x[i][j + 1]));
		}
	}
	
	ll ans = *min_element(dp[n - 2].begin(), dp[n - 2].end());
	if(ans == INF){
		ans = -1;
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
	
	return 0;
}