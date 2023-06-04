#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
const ll MAX = 1e5 + 7;
vector<ll> fact(MAX);
ll mult(ll a, ll b){
	a = (a + MOD) % MOD;
	b = (b + MOD) % MOD;
	return ((a * b) % MOD);
}
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
ll power(ll a, ll p){
	ll ans = 1, res = a;
	while(p > 0){
		if(p & 1){
			ans = mult(ans, res);
		}
		p >>= 1;
		res = mult(res, res);
	}
	return ans;
}
ll inv(ll a){
	return power(a, MOD - 2);
}
ll com(ll a, ll b){
	if(a < b){
		return 0ll;
	}
	ll ans = 1;
	ans = mult(ans, fact[a]);
	ans = mult(ans, inv(fact[b]));
	ans = mult(ans, inv(fact[a - b]));
	return ans;
}
void pre(){
	fact[0] = 1;
	for(int i = 1; i < MAX; ++i){
		fact[i] = mult(fact[i - 1], i);
	}
}
void solve(){
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		if(a == 0){
			++cnt;
		}
	}
	n -= cnt;
	k = min(n, k);
	ll ans = 0;
	for(int i = 0; i <= k; ++i){
		ans = add(ans, com(n, i));
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pre();
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve();
	}

	return 0;
}
