#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vll vector<vector<ll>>
const ll MOD = 1e9 + 7;
ll add(ll a, ll b){
	return ((a + b) % MOD);
}
ll sub(ll a, ll b){
	return ((((a - b) % MOD) + MOD) % MOD);
}
ll mult(ll a, ll b){
	a %= MOD;
	b %= MOD;
	return ((a * b) % MOD);
}
ll power(ll a, ll p){
	ll ans = 1;
	ll rem = a % MOD;
	while(p > 0){
		if(p & 1){
			ans = mult(ans, rem);
		}
		p >>= 1;
		rem = mult(rem, rem);
	}
	return ans;
}
ll inv(ll x){
	return power(x, MOD - 2);
}
ll divide(ll x, ll y){
	return mult(x, inv(y));
}
ll add(vl v){
	ll ans = 0;
	for(ll elem : v){
		ans = add(ans, elem);
	}
	return ans;
}
ll mult(vl v){
	ll ans = 1;
	for(ll elem : v){
		ans = mult(ans, elem);
	}
	return ans;
}
ll rec(vll v){
	ll ans = 0;
	for(vl vv : v){
		ans = add(ans, mult(vv));
	}
	return ans;
}

void solve(){
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = divide(mult(n * m, n * m + 1), 2);
	map<ll, ll> row, col;
	for(int i = 0; i < k; ++i){
		ll q, ind, val;
		cin >> q >> ind >> val;
		if(q == 0){
			if(row.find(ind) == row.end()){
				row[ind] = 1;
			}
			row[ind] = mult(row[ind], val);
		}else{
			if(col.find(ind) == col.end()){
				col[ind] = 1;
			}
			col[ind] = mult(col[ind], val);
		}
	}
	auto get_row = [&](ll r){
		ll ans = mult((vl){m, m + 1, inv(2)});
		ans = add(ans, mult((vl){m, m, r - 1}));
		return ans;
	};
	auto get_col = [&](ll c){
		ll ans = mult((vl){m, n, n - 1, inv(2)});
		ans = add(ans, mult(c, n));
		return ans;
	};
	for(auto [r, x] : row){
		ll tmp = mult(get_row(r), x - 1);
		ans = add(ans, tmp);
	}
	for(auto [c, y] : col){
		ll tmp = mult(get_col(c), y - 1);
		ans = add(ans, tmp);
	}
	ll sum_y = 0, sum_c = 0, sum_cy = 0, w = col.size();
	for(auto [c, y] : col){
		sum_y = add(sum_y, y);
		sum_c = add(sum_c, c);
		sum_cy = add(sum_cy, mult(c, y));
	}
	for(auto [r, x] : row){
		ll to_add = rec((vll){(vl){m, r - 1, x, sum_y}, (vl){x, sum_cy}, (vl){m, r - 1, w}, (vl){sum_c}});
		ll to_sub = rec((vll){ (vl){m, r - 1, x, w }, (vl){m, r - 1, sum_y }, (vl){x, sum_c }, (vl){sum_cy } });
		ans = add(ans, to_add);
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
