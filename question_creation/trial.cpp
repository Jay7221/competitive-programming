#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n;
	cin >> n;
	map<ll, vector<ll> > index;
	for(ll i = 1; i < n + 1; ++i){
		ll a;
		cin >> a;
		index[a].push_back(i);
	}
	ll ans = 0;
	for(ll x = 1; x < n + 1; ++x){
		ll prev = 1;
		for(auto i : index[x]){
			ll l = max(prev, i - x + 1),  r = min(n, i + x - 1);
			ans  += max(0ll, r - l + 1 - x + 1);
			prev = i + 1;
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