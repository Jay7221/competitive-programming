#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define MAX (int)(1e9 + 7)
void solve(){
	int a, b;
	cin >> a >> b;
	vector<vector<int> > dp(a + 1, vector<int>(b + 1, MAX));
	for(int i = 1; i < min(a + 1, b + 1); i++)
		dp[i][i] = 0;
	for(int i = 1; i < a + 1; i++){
		for(int j = 1; j < b + 1; j++){
			for(int k = 1; k < i; k++)
				dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
			for(int k = 1; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
		}
	}
	cout << dp[a][b] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}