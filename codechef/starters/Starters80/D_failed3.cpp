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
ll add(vector<ll> v){
	ll ans = 0;
	for(ll elem : v){
		ans = add(ans, elem);
	}
	return ans;
}
ll mult(vector<ll> v){
	ll ans = 0;
	for(ll elem : v){
		ans = mult(ans, elem);
	}
	return ans;
}
ll add(ll a, ll b, ll c){
	return add(a, add(b, c));
}
ll mult(ll a, ll b, ll c){
	return mult(a, mult(b, c));
}
ll mult(ll a, ll b, ll c, ll d){
	return mult(a, mult(b, c, d));
}
ll rec(vector<vector<ll>> v){
	ll ans = 0;
	for(vector<ll> vv : v){
		ans = add(ans, mult(vv));
	}
	return ans;
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
	auto get_row = [&](ll r){
		ll ans = mult(m, m + 1);
		ans = divide(ans, 2);
		ans = add(ans, mult(m, m, r - 1));
		return ans;
	};
	auto get_col = [&](ll c){
		ll ans = mult(m, n, n - 1);
		ans = divide(ans, 2);
		ans = add(ans, mult(n, c));
		return ans;
	};
	ans = mult(n, m);				// ans = n * m
	ans = mult(ans, add(ans, 1));	// ans = ans * (ans + 1)
	ans = divide(ans, 2);				// ans = ans / 2		So overall ans = (n * m) * (n * m + 1) / 2
	ll sum_r = 0, sum_rx = 0, sum_x = 0, sum = 0;
	for(auto [r, x] : row_q){
		ll tmp = mult(get_row(r), x - 1);
		ans = add(ans, tmp);
	}
	for(auto [c, y] : col_q){
		ll tmp = mult(get_col(c), y - 1);
		ans = add(ans, tmp);
	}
	ll sum_y = 0, sum_cy = 0, sum_c = 0, w = 0;
	for(auto [c, y] : col_q){
		sum_c = add(sum_c, c);
		sum_y = add(sum_y, y);
		sum_cy = add(sum_cy, mult(c, y));
		++w;
	}
	for(auto [r, x] : row_q){
		ll to_add = add(mult(r - 1, m, x, sum_y), mult(x, sum_cy));
		ans = add(ans, to_add);

		ll com1 = mult(m, mult(r - 1, x - 1, w));

		ll com2 = mult(x - 1, sum_c);	
		
		ll com3 = mult(m, r - 1, sum_y);	
	
		ll com4 = sum_cy;	

		ll to_sub = add((vector<ll>){com1, com2, com3, com4});
		ans = sub(ans, to_sub);
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
