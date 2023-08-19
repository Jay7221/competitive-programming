#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	if(n % 4 == 1 || n % 4 == 2){
		cout << 0 << '\n';
		return ;
	}
	int mx = n * (n + 1) / 4 + 1;
	vector<vector<int> > dp(n + 1, vector<int>(mx, 0));
	dp[0][0] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < mx ; j++){
			dp[i][j] = dp[i - 1][j];
			if(j - i >= 0){
				dp[i][j] += dp[i - 1][j - i];
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[n - 1][mx - 1] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}