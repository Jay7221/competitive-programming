#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	ll ans = 0;
	for(ll p = 30; p > -1; p--){
		ll t = n;
		for(ll i = 0; i < n; i++){
			if(a[i] & (1 << p)){
				t--;
			}
		}
		if(t <= k){
			k -= t;
			ans += (1 << p);
		}
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