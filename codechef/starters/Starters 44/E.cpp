#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define mx (int)(1e6 + 7)
vector<ll> fact(mx), invFact(mx), inv(mx);
void pre(){
	fact[0] = 1, invFact[0] = 1;
	fact[1] = 1, invFact[1] = 1;
	inv[1] = 1;
	for(ll i = 2; i < mx; ++i){
		fact[i] = fact[i - 1] * i;
		inv[i] = (mod / i) * (mod - inv[mod % i]);

		fact[i] %= mod;
		inv[i] %= mod;
	}
	for(int i = 2; i < mx; ++i){
		invFact[i] = invFact[i - 1] * inv[i];
		invFact[i] %= mod;
	}
}
ll com(int n, int k){
	ll ans = fact[n];
	ans *= invFact[k];
	ans %= mod;
	ans *= invFact[n - k];
	ans %= mod;
	return ans;
}
void solve(){
	int n, m;
	cin >> n >> m;
	int y = (n + m - 1) / m;
	ll ans = com(m + n, m) - com(m + y - 1, m);
	ans %= mod;
	ans += mod;
	ans %= mod;
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}