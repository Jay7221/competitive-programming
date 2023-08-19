#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){for(auto k : c){for(auto t : k){cerr << t << ' ' ;} cerr << '\n';} cerr << '\n';} cerr << '\n';
ll compute(string s){
	ll n = s.size();
	vector<ll> num(n);
	for(ll i = 0; i < n; i++)
		num[i] = s[i] - '0';
	if(n == 1 && num[0] == 0)
		return 0;
	vector<vector<vector<ll> > > dp(n, vector<vector<ll> >(10, vector<ll>(2, 0)));
	for(ll i = 1; i < num[0]; i++)
		dp[0][i][0] = 1;
	dp[0][num[0]][1] = 1;
	for(ll i = 1; i < n; i++){
		for(ll j = 0; j < 10; j++){
			dp[i][j][0] += (j != 0);
			for(ll k = 0; k < 10; k++){
				if(j == k)
					continue ;
				dp[i][j][0] += dp[i - 1][k][0];
			}
			// cerr << dp[i][j][0] << '\n';
		}
		for(ll j = 0; j < num[i]; j++){
			if(j == num[i - 1])
				continue ;
			dp[i][j][0] += dp[i - 1][num[i - 1]][1];
		}
		if(num[i - 1] != num[i]){
			dp[i][num[i]][1] += dp[i - 1][num[i - 1]][1];
		}
	}
	ll ans = 0;
	for(ll i = 0; i < 10; i++)
		ans += dp[n - 1][i][0];
	ans += dp[n - 1][num[n - 1]][1];
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
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}