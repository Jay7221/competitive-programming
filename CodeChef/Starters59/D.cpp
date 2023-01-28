#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	const int MOD = 1e9 + 7;
	auto add = [&](ll a, ll b){
		return ((a + b) % MOD);
	};
	auto mult = [&](ll a, ll b){
		return ((a * b) % MOD);
	};
	auto sub = [&](ll a, ll b){
		return ((((a - b) % MOD) + MOD) % MOD);
	};
	ll n, k;
	cin >> n >> k;
	ll s[n + 1];
	s[0] = 0;
	for(int i = 1; i <= n; ++i)
		cin >> s[i];
	ll dp[n + 1][n + 1][2][n + 1];
	for(int index = 0; index <= n; ++index){
		for(int beauty = 0; beauty <= n; ++beauty){
			for(int parity = 0; parity <= 1; ++parity){
				for(int terms = 0; terms <= n; ++terms){
					dp[index][beauty][parity][terms] = 0;
				}
			}
		}
	}
	dp[0][0][0][0] = 1;
	dp[0][0][1][0] = 1;
	for(int index = 1; index <= n; ++index){
		for(int beauty = 1; beauty <= index; ++beauty){
			for(int parity = 0; parity <= 1; ++parity){
				if((s[index] != 0) && ((s[index] % 2) != parity))
					continue ;
				for(int terms = 1; terms <= index; ++terms){
					dp[index][beauty][parity][terms] = add(dp[index][beauty][parity][terms],
						dp[index - 1][beauty][parity][terms - 1]);
					dp[index][beauty][parity][terms] = add(dp[index][beauty][parity][terms],
						dp[index - 1][beauty - 1][parity ^ 1][index - terms]);
				}
			}
		}
	}
	int even = n / 2, odd = (n + 1) / 2;
	ll ans = add(dp[n][k][0][even], dp[n][k][1][odd]);
	for(int i = 1; i <= n; ++i){
		if(s[i]){
			if(s[i] % 2)
				--odd;
			else
				--even;
		}
	}
	for(ll i = 1; i <= even; ++i)
		ans = mult(ans, i);
	for(ll i = 1; i <= odd; ++i)
		ans = mult(ans, i);
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}