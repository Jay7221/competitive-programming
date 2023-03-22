#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll a, ll b){
	a %= MOD;
	b %= MOD;
	return ((a + b) % MOD);
}
ll sub(ll a, ll b){
	a %= MOD;
	b %= MOD;
	return ((((a - b) % MOD) + MOD) % MOD);
}
ll mult(ll a, ll b){
	a %= MOD;
	b %= MOD;
	return ((a * b) % MOD);
}
ll power(ll a, int p){
	ll ans = 1, rem = a;
	while(p > 0){
		if(p & 1){
			ans = mult(ans, rem);
		}
		rem = mult(rem, rem);
		p >>= 1;
	}
	return ans;
}
ll inv(ll x){
	return power(x, MOD - 2);
}
ll divide(ll a, ll b){
	return mult(a, inv(b));
}
void solve(){
	ll n, m, k;
	cin >> n >> m >> k;
	map<ll, ll> row_q, col_q;
	for(int i = 0; i < k; ++i){
		ll q, x, v;
		cin >> q >> x >> v;
		if(q == 0){
			if(row_q.find(x) == row_q.end()){
				row_q[x] = 1;
			}
			row_q[x] = mult(row_q[x], v);
		}else{
			if(col_q.find(x) == col_q.end()){
				col_q[x] = 1;
			}
			col_q[x] = mult(col_q[x], v);
		}
	}
	auto row_sum = [&](ll i){
		ll ans;
		ans = (m  * (m + 1)) / 2;
		ans = add(ans, mult(m, mult(m, i - 1)));
		return ans;
	};
	ll ans = divide(mult(mult(n, m), add(mult(n, m), 1)), 2);
	ll sum_v = n;
	ll sum_iv = divide(mult(n, n - 1), 2);
	for(auto [x, v] : row_q){
		ll s = row_sum(x);
		ans = add(ans, mult(v - 1, s));
		sum_v = add(sum_v, v - 1);
		sum_iv = add(sum_iv, mult(x - 1, v - 1));
	}
	for(auto [x, v] : col_q){
		ll s = add(mult(m, sum_iv), mult(x, sum_v));
		ans = add(ans, mult(s, v - 1));
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
