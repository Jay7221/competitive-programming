#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD;
void solve(){
	int n;
	cin >> n;
	cin >> MOD;
	auto add = [&](ll a, ll b){
		return (a + b) % MOD;
	};
	auto sub = [&](ll a, ll b){
		return (a - b + MOD) % MOD;
	};
	auto mult = [&](ll a, ll b){
		return (a * b) % MOD;
	};
	ll MAX = n + 10;
	ll fact[MAX], invFact[MAX], inv[MAX];
	fact[0] = 1;
	invFact[0] = 1;
	ll ans = 0;
	fact[1] = invFact[1] = 1;
	inv[1] = 1;
	for(int i = 2; i < MAX; ++i){
		inv[i] = mult(MOD - inv[MOD % i], MOD / i);
		fact[i] = mult(fact[i - 1], i);
		invFact[i] = mult(invFact[i - 1], inv[i]);
	}
	auto com = [&](ll n, ll k){
		if(n < k)
			return 0ll;
		if(k < 0)
			return 0ll;
		ll ans = mult(fact[n], invFact[k]);
		ans = mult(ans, invFact[n - k]);
		return ans;
	};
	if(n % 2 == 0){
		ans = fact[n - 2];
	}
	for(ll k = 2; k <= (n + 1) / 2; ++k){
		for(int i = 0; i <= k - 2; ++i){
			ll tmp = mult(com(k - 2, i), fact[n - i - 3]);
			if(n % 2 == 0)
				tmp = mult(tmp, k);
			else
				tmp = mult(tmp, k - 1);
			ans = add(ans, tmp);
		}
	}
	ans = mult(ans, n);
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}