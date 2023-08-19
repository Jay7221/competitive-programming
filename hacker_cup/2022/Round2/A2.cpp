#include<bits/stdc++.h>
using namespace std;
#define ll long long
class StringHash{
private:
	ll n;
	vector<int> s;
	vector<ll> pre, pow, inv_pow;
	ll MOD;
	ll base;
public:
	ll mult(ll a, ll b){
		return ((a * b) % MOD);
	}
	ll add(ll a, ll b){
		return ((a + b) % MOD);
	}
	ll sub(ll a, ll b){
		return ((((a - b) % MOD) + MOD) % MOD);
	}
	ll power(ll a, ll p){
		ll cur = a, ans = 1;
		while(p){
			if(p & 1){
				ans = mult(ans, cur);
			}
			cur = mult(cur, cur);
			p >>= 1;
		}
		return ans;
	}
	StringHash(string& s, int m):s(s), MOD(m){
		n = s.size();
		++n;
		
		pre.resize(n);
		for(int i = 1; i < n; ++i){
			pre[i] = s[i - 1];
		}
		base = 1e9 + 20;
		ll cur = 1;
		for(int i = 0; i < n; ++i){
			pre[i] = mult(pre[i], cur);
			cur = mult(cur, base);
		}
		for(int i = 1; i < n; ++i)
			pre[i] = add(pre[i], pre[i - 1]);


		pow.resize(n);
		inv_pow.resize(n);
		pow[0] = 1, inv_pow[0] = 1;
		pow[1] = base, inv_pow[1] = power(base, MOD - 2);
		for(int i = 2; i < n; ++i){
			pow[i] = mult(pow[i - 1], base);
			inv_pow[i] = mult(inv_pow[i - 1], inv_pow[1]);
		}
	}
	ll hash(int l, int r){
		ll ans = sub(pre[r], pre[l - 1]);
		ans = mult(ans, inv_pow[l]);
		return ans;
	}
}
void solve(){
	int n;
	cin >> n;
	vector<int> s(n);
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	int q;
	cin >> q;
	StringHash H1(s, 1e9 + 7);
	int ans = 0;
	while(q--){
		int l, r ;
		cin >> l >> r;
		if(l == r){
			++ans;
			continue ;
		}
		if((r - l + 1) % 2 == 0){
			continue ;
		}
		int mid = (l + r) / 2;
		
	}
}
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		solve();
	}
}