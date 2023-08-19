#include<bits/stdc++.h>
using namespace std;
#define mx (int)(4e6 + 7)
#define ll long long
#define mod (ll)(998244353)
vector<ll> fact(mx), invFact(mx), inv(mx);
void pre(){
	fact[0] = 1, fact[1] = 1;
	inv[1] = 1;
	invFact[0] = 1, invFact[1] = 1;
	for(ll i = 2; i < mx; ++i){
		inv[i] = ( ( (mod - (mod / i)) * (inv[mod % i]) ) % mod);
		fact[i] = ((i * fact[i - 1]) % mod);
		invFact[i] = (invFact[i - 1] * inv[i]) % mod;
	}
}
ll com(int n, int k){
	if(n < k)
		return 0ll;
	if(k < 0)
		return 0ll;
	ll ans = fact[n];
	ans *= invFact[n - k]; 
	ans %= mod;
	ans *= invFact[k];
	ans %= mod;
	return ans;
}
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> c(2), d(2);
	c[0] = c[1] = 0;
	d[0] = d[1] = 1;
	ll ans = 0;
	for(int i = 0; i < 20; ++i){
		d[(k >> i) & 1] *= 2;
	}
	for(int i = 19; i >= -1; --i){
		if(i != -1){
			c[(k >> i) & 1] *= 2;
			d[(k >> i) & 1] /= 2;
			if(!(m & (1 << i)))
				continue ;
		}
		ll tmp = com(c[0] * d[0] + (d[0] - 1) + n, n) - com(c[0] * d[0] + n - 1, n);
		tmp *= com(c[1] * d[1] + (d[1] - 1) + n, n) - com(c[1] * d[1] + n - 1, n);
		tmp %= mod;
		tmp %= mod;
		ans = (ans + tmp) % mod;
		ans += mod;
		ans %= mod;
		if(i != -1){
			++c[(k >> i) & 1];
		}
	}
	cout << ans << '\n';
}
int main(){
	freopen("inputf.in","r",stdin);
	freopen("outputf.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}