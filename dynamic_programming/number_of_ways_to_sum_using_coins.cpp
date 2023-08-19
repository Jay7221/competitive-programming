#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define mx (int)(1e5)
int solve(int k, int s, vector<int>& w, vector<vector<int> >& dp){
	if(s == 0)
		return 1;
	if((k < 0) || (s < 0))
		return 0;
	if(dp[k][s] != 0)
		return dp[k][s];
	int ans = 0;
	for(int i = 0; i < k + 1; ++i){
		ans += solve(i - 1, s - w[i], w, dp);
	}
	return dp[k][s] = ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> w(n);
	for(int i = 0; i < n; ++i)
		cin >> w[i];
	vector<vector<int> > dp(n, vector<int>(mx));
	for(int i = 0; i < n; ++i)
		dp[i][0] = 1;
	int s;
	cin >> s;
	cout << solve(n - 1, s, w, dp) << '\n';
}