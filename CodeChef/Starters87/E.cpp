#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
ll add(ll a, ll b){
	return ((a + b) % MOD);
}
ll sub(ll a, ll b){
	return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
	return ((a * b) % MOD);
}
ll power(ll a, ll p){
	ll ans = 1, res = a;
	while(p){
		if(p & 1){
			ans = mult(ans, res);
		}
		res = mult(res, res);
		p >>= 1;
	}
	return ans;
}
ll inv(ll a){
	return power(a, MOD - 2);
}
void solve(){
	ll n, m;
	cin >> n >> m;
	ll ans;
	if(m % 2 == 0){
		ans = inv(2);
	}else{
		ll k = m / 2;
		ll mn = power(m, n);
		ans = add(
					inv(mn),
					mult(
						k,
						mult(
							sub(mn, 1),
							inv(
								mult(mn, sub(m, 1))
							)
						)
					)
				);
	}
	cout << ans << '\n';
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
	
	return 0;
}