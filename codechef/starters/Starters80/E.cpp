#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll a, ll b){
	a = (a + MOD) % MOD;
	b = (b + MOD) % MOD;
	return ((a + b) % MOD);
}
ll sub(ll a, ll b){
	a = (a + MOD) % MOD;
	b = (b + MOD) % MOD;
	return ((a - b + MOD) % MOD);
}
ll mult(ll a, ll b){
	a = (a + MOD) % MOD;
	b = (b + MOD) % MOD;
	return ((a * b) % MOD);
}
ll power(ll a, ll p){
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
class SegmentTree{
	public:
		vector<ll> tree;
		int n;
		SegmentTree(int sz){
			n = 1;
			while(n < sz){
				n <<= 1;
			}
			tree.assign(2 * n, 0ll);
		}
		void set(int ind, int val){
			ind += n;
			tree[ind] = val;
			ind /= 2;
			while(ind > 0){
				tree[ind] = add(tree[2 * ind], tree[2 * ind + 1]);
				ind /= 2;
			}
		}
		ll get(int l, int r){
			l += n;
			r += n;
			ll ans = 0;
			while(l <= r){
				if(l % 2 == 1){
					ans = add(ans, tree[l]);
					++l;
				}
				if(r % 2 == 0){
					ans = add(ans, tree[r]);
					--r;
				}
				l /= 2;
				r /= 2;
			}
			return ans;
		}
};
void solve(){
	int n;
	cin >> n;
	vector<ll> x(n), w(n);
	for(int i = 0; i < n; ++i){
		cin >> x[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> w[i];
	}
	map<ll, int> index;
	for(int i = 0; i < n; ++i){
		index[x[i]] = i;
	}
	vector<pair<ll, ll>> v(n);
	for(int i = 0; i < n; ++i){
		v[i] = {w[i], x[i]};
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	SegmentTree s1(n), s2(n);
	// s1 = 2 ^ wi
	// s2 = xi * 2 ^ wi
	for(auto [W, X] : v){
		int i = index[X];
		ll tmp = 0;

		tmp = mult(X, s1.get(0, i - 1));
		tmp = sub(tmp, s2.get(0, i - 1));
		tmp = mult(tmp, power(2, n - W));
		ans = add(ans, tmp);

		tmp = mult(X, s1.get(i + 1, n - 1));
		tmp = sub(tmp, s2.get(i + 1, n - 1));
		tmp = mult(tmp, -1);
		tmp = mult(tmp, power(2, n - W));
		ans = add(ans, tmp);

		s1.set(i, power(2, W - 1));
		s2.set(i, mult(X, power(2, W - 1)));
	}
	ans = divide(ans, power(2, n));
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
