#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<ll> > left(n + 2, vector<ll>(m + 2)), top(n + 2, vector<ll>(m + 2)), dp(n + 2, vector<ll>(m + 2)), dp_left(n + 2, vector<ll>(m + 1)), dp_top(n + 2, vector<ll>(m + 2));
	for(int i = 1; i < n + 1; ++i){
		for(int j = 1; j < m + 1; ++j){
			cin >> left[i][j];
		}
	}
	for(int i = 1; i < n + 1; ++i){
		for(int j = 1; j < m + 1; ++j){
			cin >> top[i][j];
		}
	}
	for(int i = 1; i < n + 1; ++i){
		for(int j = 1; j < m + 1; ++j){
			dp_left[i][j] = dp_left[i][j - 1] + left[i][j];
		}
	}
	for(int i = 1; i < n + 1; ++i){
		for(int j = 1; j < m + 1; ++j){
			dp_top[i][j] = dp_top[i - 1][j] + top[i][j];
		}
	}
	for(int i = 1; i < n + 1; ++i){
		for(int j = 1; j < m + 1; ++j){
			dp[i][j] = max(dp[i][j - 1] + dp_top[i][j], dp[i - 1][j] + dp_left[i][j]);
		}
	}
	cout << dp[n][m] << '\n';
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