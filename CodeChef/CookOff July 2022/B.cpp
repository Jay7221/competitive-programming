#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx (ll)(1e7 + 7)
#define mx2 (ll)(1e5 + 7)
#define mod (ll)(1e9 + 7)
vector<ll> fact(mx), inv(mx), invFact(mx);
void pre(){
	fact[0] = fact[1] = 1;
	invFact[0] = invFact[1] = 1;
	inv[1] = 1;
	for(int i = 2; i < mx; ++i){
		inv[i] = (mod - mod / i) * (inv[mod % i]);
		inv[i] %= mod;
	}
	for(int i = 2; i < mx; ++i){
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		invFact[i] = inv[i] * invFact[i - 1];
		invFact[i] %= mod;
	}
}
ll com(int n, int k){
	if(n < k){
		return 0ll;
	}
	ll ans = fact[n];
	ans *= invFact[n - k];
	ans %= mod;
	ans *= invFact[k];
	ans %= mod;
	return ans;
}
ll pow__(int p){
	ll ans = 2, rem = 1;
	while(p){
		if(p & 1){
			rem *= ans;
			rem %= mod;
		}
		ans *= ans;
		ans %= mod;
		p >>= 1;
	}
	return rem;
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	map<int, int> freq;
	map<ll, ll> num;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		++freq[a[i]];
	}
	ll ans = 0;
	for(auto p : freq){
		int s, f;
		tie(s, f) = p;
		ans += pow__(f) - ( f + 1 );
		ans %= mod;
		if(s < n + 1 && s > 1){
			num[s] += f;
			ans -= com(f, s);
			ans = (ans + mod) % mod;
		}
		for(int d = 2; d <= sqrt(s); ++d){
			if(s % d)
				continue ;
			ans -= com(f, d);
			ans = (ans + mod) % mod;
			num[d] += f;
			if(d * d != s && s / d < n + 1){
				num[s / d] += f;
				ans -= com(f, s / d);
				ans = (mod + ans) % mod;
			}
		}
	}
	for(auto c : num){
		int d, f;
		tie(d, f) = c;
		ans += com(f, d);
		ans %= mod;
	}
	// cerr <<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=////";
	// cerr << '\n';
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