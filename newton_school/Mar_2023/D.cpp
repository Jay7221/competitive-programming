#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 998244353;
ll add(ll a, ll b){
	a = (a % MOD + MOD) % MOD;
	b = (b % MOD + MOD) % MOD;
	return ((a + b) % MOD);
}
ll sub(ll a, ll b){
	a = (a % MOD + MOD) % MOD;
	b = (b % MOD + MOD) % MOD;
	return ((a - b + MOD) % MOD);
}
ll mult(ll a, ll b){
	a = (a % MOD + MOD) % MOD;
	b = (b % MOD + MOD) % MOD;
	return ((a * b) % MOD);
}
ll power(ll a, ll p){
	ll ans = 1, res = a;
	while(p > 0){
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
	ll sum[m + 1];
	for(int k = 1; k <= m; ++k){
		ll p = m / k;
		p = mult(p, p + 1);
		p = mult(p, inv(2));
		p = power(p, n);
		p = mult(p, power(k, n));
		sum[k] = p;
	}
	for(int k = m; k > 0; --k){
		for(int j = 2; j * k <= m; ++j){
			sum[k] = sub(sum[k], sum[k * j]);
		}
	}
	ll ans = 0;
	for(int k = 1; k <= m; ++k){
		ans = add(ans, mult(sum[k], inv(k)));
	}
	cout << ans << '\n';
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
