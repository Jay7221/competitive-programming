#include<iostream>
using namespace std;
const int INF = 1e9 + 7;
void solve(){
	int n, q;
	cin >> n >> q;
	int a[n + 1];
	string s;
	cin >> s;
	for(int i = 1; i <= n; ++i)
		a[i] = s[i - 1] - 'A';
	a[0] = 5;
	int dp[n + 1][3];
	for(int k =0; k < 3; ++k)
		dp[0][k] = 0;
	for(int i = 1; i <= n; ++i){
		for(int k = 0; k < 3; ++k)
			dp[i][k] = dp[i - 1][k];
		if(a[i] != a[i - 1]){
			++dp[i][a[i]];
		}
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		int ans = INF;
		for(int k = 0; k < 3; ++k){
			int tmp = 0;
			for(int other = 0; other < 3; ++other){
				if(other != k){
					tmp += dp[r][other] - dp[l - 1][other];
				}
			}
			ans = min(ans, tmp);
		}
		cout << ans << '\n';
	}
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
	return 0;
}