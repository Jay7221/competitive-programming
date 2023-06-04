#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll a, ll b){
	a = ((a % MOD) + MOD) % MOD;
	b = ((b % MOD) + MOD) % MOD;
	return ((a + b) % MOD);
}
ll mult(ll a, ll b){
	a = ((a % MOD) + MOD) % MOD;
	b = ((b % MOD) + MOD) % MOD;
	return ((a * b) % MOD);
}
ll sub(ll a, ll b){
	a = ((a % MOD) + MOD) % MOD;
	b = ((b % MOD) + MOD) % MOD;
	return (((a - b) % MOD + MOD) % MOD);
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
ll inv(ll a){
	return power(a, MOD - 2);
}
vector<ll> fact(100);
void pre(){
	fact[0] = 1;
	for(int i = 1; i < 100; ++i){
		fact[i] = mult(fact[i - 1], i);
	}
}
ll com(ll n, ll m){
	if(n < m){
		return 0;
	}
	ll ans = mult(fact[n], inv(fact[m]));
	ans = mult(ans, inv(fact[n - m]));
	return ans;
}
void solve(){
	ll n;
	cin >> n;
	int p = 0;
	while(n > 0){
		if(n % 2 == 1){
			++p;
		}
		n /= 2;
	}
	ll ans = 0;
	for(int k = 2; k < p; ++k){
		ans = add(ans, mult(com(p, p - k), sub(power(2, k), 2)));
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	pre();
	for(int t = 1; t <= T; ++t){
		solve();
	}
}
