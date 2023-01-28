#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
const int MAX = 1e5;
ll fact[MAX], inv[MAX], invFact[MAX];
ll add(ll a, ll b){
	return (a + b + MOD) % MOD;
}
ll sub(ll a, ll b){
	return (a - b + MOD) % MOD;
}
ll mult(ll a, ll b){
	return (a * b) % MOD;
}
void pre(){
	fact[0] = 1;
	for(int i = 1; i < MAX; ++i)
		fact[i] = mult(fact[i - 1], i);
	inv[1] = 1;
	for(int i = 2; i < MAX; ++i){
		inv[i] = add(MOD, -inv[MOD % i]);
		inv[i] = mult(inv[i], MOD / i);
	}
	invFact[0] = 1;
	for(int i = 1; i < MAX; ++i)
		invFact[i] = mult(invFact[i - 1], inv[i]);
}
ll com(ll n, ll k){
	if(n < k)
		return 0ll;
	ll ans = mult(fact[n], invFact[k]);
	ans = mult(ans, invFact[n - k]);
	return ans;
}
void solve(){
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = 0;
	ll dp1[k + 1];
	// dp1[i] = number of ways that i type of shirts are worn, given the i types
	dp1[0] = 0;
	for(int i = 1; i <= k; ++i){
		dp1[i] = pow(i, n);
		for(int j = 1; j < i; ++j){
			dp1[i] = sub(dp1[i], mult(com(i, j), dp1[j]));
		}
	}
	for(ll kk = k; kk > 0; --kk){
		ll tmp = mult(com(m, kk), dp1[kk]);
		ans = add(ans, tmp);
	}
	cout << ans << '\n';
	return;
}
int main(){
	pre();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
