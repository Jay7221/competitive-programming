#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll MOD = 1e9 + 7;
const ll MAX = 1e5 + 7;
vector<ll> inv(MAX), fact(MAX), invfact(MAX);
void pre(){
	fact[0] = 1;
	inv[1] = 1;
	invfact[0] = 1;
	for(ll i = 2; i < MAX; ++i){
		inv[i] = (inv[MOD % i] * (MOD - MOD / i)) % MOD;
		inv[i] %= MOD;
	}
	for(ll i = 1; i < MAX; ++i){
		fact[i] = (fact[i - 1] * i);
		fact[i] %= MOD;
	}
	for(ll i = 1; i < MAX; ++i){
		invfact[i] = (invfact[i - 1] * inv[i]);
		invfact[i] %= MOD;
	}
}
ll bin(ll n, ll k){
	if(k > n)
		return 0ll;
	ll ans = fact[n];
	ans = (ans * invfact[k]) % MOD;
	ans = (ans * invfact[n - k]) % MOD;
	return ans;
}
ll pow(ll p){
	ll ans = 1, cur = 2;
	while(p){
		if(p & 1){
			ans = (ans * cur) % MOD;
		}
		cur = (cur * cur) % MOD;
		p /= 2;
	}
	return ans;
}
void solve(){
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	for(ll i = 0; i <= min(n, k); ++i){
		ans += bin(n, i);
		ans %= MOD;
	}
	cout << ans << '\n';
}
int main(){
	pre();
	solve();
}