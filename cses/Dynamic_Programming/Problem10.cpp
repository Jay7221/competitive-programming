#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c :  a){for(auto k : c){cerr << k << ' ' ;} cerr<< '\n';} cerr << '\n';
#define mod (int)(1e9 + 7)
void solve(){
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
	dp[0][0] = 0;
	for(int i = 0; i < n + 1; i++){
		dp[i][0] = i;
	}
	for(int i = 0; i < m + 1; i++)
		dp[0][i] = i;
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < m + 1; j++){
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
		}
	}
	cout << dp[n][m] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}