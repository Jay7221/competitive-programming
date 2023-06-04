#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
void solve(){
	ll n, C;
	cin >> n >> C;
	vi costs(n);
	map<ll, pair<ll, ll> > specs;
	ll c, d, h;
	for(int i = 0; i < n; i++){
		cin >> c >> d >> h;
		costs[i] = c;
		specs[c] = {d, h};
	}
	sort(costs.begin(), costs.end());
	ll m;
	cin >> m;
	for(ll i = 0; i < m; i++){
		ll D, H;
		cin >> D >> H;
		ll d, h;
		bool ok = 0;
		ll ans = 1e7;
		for(ll i = 0; i < n; i++){
			ll c = costs[i], d, h;
			tie(d, h) = specs[c];
			ll k = (D * H) / (d * h) + 1;
			if(k * c < C){
				ans = min(ans, k * c);
				ok = 1;
			}
		}
		if(!ok)
			cout << -1 << ' ';
		else
			cout << ans << ' ';

	}
}
int main(){
	int t;
	t = 1;
	while(t--){
		solve();
	}
}