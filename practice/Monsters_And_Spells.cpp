#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n;
	cin >> n;
	vector<ll> h(n), k(n);
	for(int i = 0; i < n; i++)
		cin >> k[i];
	for(int i = 0; i < n; i++)
		cin >> h[i];
	vector<pair<ll, ll> > times(n);
	for(int i = 0; i < n; i++){
		times[i] = {k[i] - h[i], k[i]};
	}
	sort(times.begin(), times.end());
	ll ans = 0;
	ll st = -1, en = -1;
	for(auto c : times){
		ll s, e;
		tie(s, e) = c;
		if(s >= en){
			ans += ((en - st + 1) * (en - st)) / 2;
			st = s, en = e;
		}else{
			en = max(en, e);
		}
	}
	ans += ((en - st + 1) * (en - st)) / 2;
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