#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define inf (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
void solve(){
	ll n, l, k;
	cin >> n >> l >> k;
	vector<ll> d(n + 1), a(n + 1);
	d[n] = l;
	for(ll i = 0; i < n; i++)
		cin >> d[i];
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	vector<vector<ll> > dp(n + 1, vector<ll>(k + 1, inf));
	dp[0][0] = 0;
	for(int i = 0; i < k + 1; i++)
		dp[0][i] = 0;
	for(int i = 1; i < n + 1;++i){
		for(int x = 0; x < k + 1; x++){
			if(x > 0)
				dp[i][x] = min(dp[i][x], dp[i][x - 1]);
			for(int j = 0; j < x + 1; j++){
				if(i < j + 1)
					continue ;
				dp[i][x] = min(dp[i][x], dp[i - j - 1][x - j] + a[i - j - 1] * (d[i] - d[i - j - 1]));
			}
		}
	}
	cout << dp[n][k] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
