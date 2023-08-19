#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n), pos(n);
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	ll ans = 0;
	ll q = 0;		// switched numbers
	ll l = pos[0], r = pos[0];
	for(ll i = 1; i < n; i++){
		ll z = (r - l + 1) - i - q;
		ans += z * (z - 1) / 2;
		ans += z * q;
		q += z;
		if(l < pos[i] && r > pos[i])
			q--;
		l = min(l, pos[i]);
		r = max(r, pos[i]);
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