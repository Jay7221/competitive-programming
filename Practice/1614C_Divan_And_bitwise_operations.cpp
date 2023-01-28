#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n, m;
	cin >> n >> m;
	ll x = 0;
	for(int i = 0; i < m; ++i){
		ll l, r, z;
		cin >> l >> r >> z;
		x |= z;
	}
	ll ans = x;
	ans %= mod;
	for(int i = 0; i < n - 1; ++i){
		ans *= 2;
		ans %= mod;
	}
	cout << ans << '\n';
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
}