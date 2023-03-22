#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9 + 7;
ll add(ll a, ll b){
	return ((a + b) % MOD);
}
ll sub(ll a, ll b){
	a = (a + MOD) % MOD;
	b = (b + MOD) % MOD;
	return ((a - b + MOD) % MOD);
}
ll mult(ll a, ll b){
	return ((a * b) % MOD);
}
ll get(ll n, ll mod){
	n = (n * (n + 1)) / 2;
	n = n % mod;
	return n;
}
void solve(){
	ll n, x, p;
	cin >> n >> x >> p;
	p = min(p, 4 * n);
	for(ll f = 1; f <= p; ++f){
		if(((get(f, n) + x) % n) == 0){
			cout << "YES\n";
			return ;
		}
	}
	cout << "NO\n";
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
