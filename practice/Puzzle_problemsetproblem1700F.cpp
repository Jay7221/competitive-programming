#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define inf (int)(1e9 + 7)
string s, t;
vector<vector<int> > dp(1000, vector<int>(1000, inf));
int solve(int i, int j){
	if(dp[i][j] != inf)
		return dp[i][j];
	int ans = max(solve(i - 1, j), solve(i, j - 1));
	if(s[i] == t[j]){
		ans = max(solve(i - 1, j - 1) + 1, ans);
	}
	return dp[i][j] = ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s >> t;
	int n = s.size() -1 , m = t.size() - 1;
	for(auto &c : dp[0])
		c = 0;
	for(auto &c : dp)
		c[0] = 0;
	cout << solve(n, m) << '\n';
}