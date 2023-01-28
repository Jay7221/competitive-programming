#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
ll compute(string s){
	int n = s.size();
	vector<vector<vector<vector<ll> > > > dp(n, vector<vector<vector<ll> > >(10, vector<vector<ll> >(2, vector<ll>(2, 0))));
	vector<int> num(n);
	for(int i = 0; i < n; i++){
		num[i] = s[i] - '0';
	}
	dp[0][0][0][1] = 1;
	for(int i = 1; i < num[0]; i++)
		dp[0][i][0][0] = 1;
	if(num[0] != 0){
		dp[0][num[0]][1][0] = 1;
	}
	for(int i = 1; i < n; i++){
		dp[i][0][0][1] = dp[i - 1][0][0][1];
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < 10; k++){
				if(j == k)
					continue;
				dp[i][j][0][0] += dp[i - 1][k][0][0];
				dp[i][j][0][0] += dp[i - 1][k][0][1];
			}
		}
		for(int j = 0; j < num[i]; j++){
			if(j == num[i - 1])
				continue ;
			dp[i][j][0][0] += dp[i - 1][num[i - 1]][1][0];
		}
		if(num[i] != num[i - 1]){
			dp[i][num[i]][1][0] += dp[i - 1][num[i - 1]][1][0];
		}
	}
	// for(int i = 0; i < n ; i++){
	// 	for(int j = 0; j < 10; j++){
	// 		cerr << dp[i][j][0][0] << ' ';
	// 	}
	// 	cerr << '\n';
	// }
	// for(int i = 0; i < n ; i++){
	// 	for(int j = 0; j < 10; j++){
	// 		cerr << dp[i][j][1][0] << ' ';
	// 	}
	// 	cerr << '\n';
	// }
	ll ans = 0;
	for(int i = 0; i < 10; i++){
		ans += dp[n - 1][i][0][0];
		ans += dp[n - 1][i][0][1];
	}
	ans += dp[n - 1][num[n - 1]][1][0];
	return ans ;
}
bool check(string s){
	int n = s.size();
	for(int i = 0; i < n - 1; i++){
		if(s[i] == s[i + 1])
			return 0;
	}
	return 1;
}
void solve(){
	string a, b;
	cin >> a >> b;
	ll ans = compute(b) - compute(a);
	if(check(a))
		ans += 1;
	cout << ans << '\n';
	// cout << compute("0") << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}