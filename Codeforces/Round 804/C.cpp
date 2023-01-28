#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define mx (int)(1e5 + 7)
vector<ll> fact(mx), inv(mx), invFact(mx);
void pre(){
	fact[0] = fact[1] = 1;
	invFact[0] = invFact[1] = 1;
	inv[1] = 1;
	for(int i = 2; i < mx; ++i){
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		inv[i] = (mod - mod / i) * inv[mod % i];
		inv[i] %= mod;
		invFact[i] = invFact[i - 1] * inv[i];
		invFact[i] %= mod;
	}
}
ll com(int n, int k){
	if(n < k)
		return 0ll;
	ll ans = fact[n];
	ans *= invFact[n - k];
	ans %= mod;
	ans *= invFact[k];
	ans %= mod;
	return ans;
}
ll per(int n, int k){
	ll ans = com(n, k);
	ans *= fact[k];
	ans %= mod;
	return ans;
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), pos(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		pos[a[i]] = i;
	}
	int l = pos[0], r = pos[0];
	ll ans = 1;
	for(int k = 1; k < n; ++k){
		int t = pos[k];
		int s = max(r, t) - min(l, t) + 1;
		int p = s - k - 1;
		int q = max(0, l - t - 1) + max(0, t - r - 1);
		ans *= per(p, q);
		ans %= mod;
		l = min(l, t);
		r = max(r, t);
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}