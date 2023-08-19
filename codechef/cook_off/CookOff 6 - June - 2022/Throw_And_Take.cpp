#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
void solve(){
	ll n;
	cin >> n;
	vector<ll> c(n), v(n);
	for(ll i = 0; i < n; ++i){
		cin >> c[i];
		c[i] %= 2;
	}
	for(ll i = 0; i < n; ++i){
		cin >> v[i];
	}
	vector<ll> coin;
	for(ll i = 0; i < n; ++i){
		if(c[i] == 1){
			coin.push_back(v[i]);
		}
	}
	n = coin.size();
	if(n == 0){
		cout << 0 << '\n';
		return ;
	}
	vector<ll> dp(n + 1);
	dp[n] = 0;
	for(int i = n - 1; i > -1; --i){
		dp[i] = max(dp[i + 1], coin[i] - dp[i + 1]);
	}
	cout << dp[0] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}