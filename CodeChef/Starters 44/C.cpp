#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define mx (int)(1e5 + 7)
vector<ll> v, sum(mx), sq_sum(mx);
void pre(){
	v.push_back(0);
	for(ll i = 1; i < mx; ++i){
		ll tmp = (i * (i + 1ll)) / 2ll;
		if(tmp > mod)
			break ;
		v.push_back(tmp);
	}
	for(int i = 1; i < v.size(); ++i){
		sum[i] = sum[i - 1] + v[i];
		sq_sum[i] = sq_sum[i - 1] + v[i] * v[i];
		sum[i] %= mod;
		sq_sum[i] %= mod;
	}
}
void solve(){
	ll n;
	cin >> n;
	ll k = (sqrt(1ll + 8ll * n) - 1) / 2ll;
	ll ans = n * sum[k] - sq_sum[k];
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