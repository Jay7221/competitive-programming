#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<vector<bool> > grid(n + 1, vector<bool>(n + 1, 1));
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < n + 1; j++){
			char c;
			cin >> c;
			grid[i][j] = (c != '*');
		}
	}
	vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
	dp[1][1] = 1;
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < n + 1; j++){
			if(grid[i - 1][j]){
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= mod;
			}
			if(grid[i][j - 1]){
				dp[i][j] += dp[i][j - 1];
				dp[i][j] %= mod;
			}
		}
	}
	if(grid[n][n])
		cout << dp[n][n];
	else
		cout << 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	t = 1;
	while(t--){
	solve();
	}
}