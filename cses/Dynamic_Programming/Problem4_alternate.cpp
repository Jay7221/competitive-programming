#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, target;
	cin >> n >> target;
	vector<int> coins(n + 1);
	for(int i = 1; i < n + 1; i++)
		cin >> coins[i];
	vector<vector<int> > dp(n + 1, vector<int>(target + 1, 0));
	dp[0][0] = 1;
	for(int i = 1; i < n + 1; i++){
		for(int j = 0; j < target + 1; j++){
			dp[i][j] = dp[i - 1][j];
			int left = j - coins[i];
			if(left >= 0){
				dp[i][j] += dp[i][left];
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[n][target] ;
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