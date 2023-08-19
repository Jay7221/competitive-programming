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
ll add(ll a, ll b, ll c){
	return add(a, add(b, c));
}
ll mult(ll a, ll b, ll c){
	return mult(a, mult(b, c));
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
	ll ans;
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
	ans = mult(n, m);				// ans = n * m
	ans = mult(ans, add(ans, 1));	// ans = ans * (ans + 1)
	ans = divide(ans, 2);				// ans = ans / 2		So overall ans = (n * m) * (n * m + 1) / 2
	ll sum_r = 0, sum_rx = 0, sum_x = 0, sum = 0;
	for(auto [r, x] : row_q){
		ll com1 = mult(m, mult(m, sub(r, 1)));
		ll com2 = divide(mult(m, add(m, 1)), 2);
		ll com = mult(x - 1, add(com1, com2));
		ans = add(ans, com);
	}
	for(auto [c, y] : col_q){
		ll com1 = mult(m, mult(n, sub(n , 1)));
		com1 = divide(com1, 2);
		ll com2 = mult(c, n);
		ll com = mult(y - 1, add(com1, com2));
		ans = add(ans, com);
	}
	for(auto [r, x] : row_q){
		sum_r = add(sum_r, r);
		sum_x = add(sum_x, x);
		sum_rx = add(sum_rx, mult(r, x));
		++sum;
	}
	for(auto [c, y] : col_q){
		ll com1 = mult(m, y - 1, sum_rx);
		ll com2 = mult(m, y - 1, sum_r);
		ll com3 = mult(sub(c, m), y - 1, sum_x);
		ll com4 = mult(sub(c, m), y - 1, sum);
		ll com5 = add(com1, com3);
		ll com6 = add(com2, com4);
		ll com = sub(add(com1, com3), add(com2, com4));
		ans = add(ans, com);
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
