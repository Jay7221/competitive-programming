#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e9;
void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	ll ans = 0;
	ll L = 0, R = MAX;
	while(L < R){
		ll mid = (L + R + 1) / 2;
		vector<ll> b(n);
		ll tot = 0;
		for(int i = 0; i < n; ++i){
			if(2 * a[i] < mid){
				++tot;
				b[i] = MAX;
			}else{
				b[i] = a[i];
			}
		}
		ll mx = 0;
		for(int i = 0; i < n - 1; ++i)
			mx = max(mx, min(b[i], b[i + 1]));
		if(mx < mid){
			++tot;
			for(int i = 0; i < n - 1; ++i)
				mx = max(mx, max(b[i], b[i + 1]));
		}
		if(mx < mid)
			++tot;
		if(tot <= k){
			L = mid;
			// ans = mid;
			// L = mid + 1;
		}else{
			R = mid - 1;
			// R = mid - 1;
		}
	}
	cout << L << '\n';
	// cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}