#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
void solve(){
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n + 2), l(n + 2, -INF), r(n + 2, INF);
	for(ll i = 1; i < n + 1; ++i){
		cin >> a[i];
		l[i] = a[i] - x;
		r[i] = a[i] + x;
	}
	ll L = l[0], R = r[0];
	ll ans = 0;
	for(ll i = 1; i < n + 1; ++i){
		L = max(L, l[i]);
		R = min(R, r[i]);
		if(L > R){
			L = l[i], R = r[i];
			++ans;
		}
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}