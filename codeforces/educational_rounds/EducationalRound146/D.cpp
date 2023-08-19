#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	ll k;
	cin >> k;
	vector<ll> d(n), f(n);
	for(int i = 0; i < n; ++i){
		cin >> f[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> d[i];
	}
	auto get = [&](ll mn, ll mx){
		int ans = 0;
		for(int i = 0; i < n; ++i){
			ll mx_d = mx / f[i];
			ll mn_d = (mn + f[i] - 1) / f[i];
			if(mx_d < mn_d){
				return n;
			}
			if((mn_d <= d[i]) && (d[i] <= mx_d)){
				continue;
			}
			++ans;
		}
		return ans;
	};
	int ans = n;
	for(int i = 0; i < n; ++i){
		ll mn = f[i] * d[i] - k;
		ll mx = f[i] * d[i];
		for(int j = 0; j <= k; ++j){
			if(mn + j < 1){
				continue;
			}
			ans = min(ans, get(mn + j, mx + j));
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

	return 0;
}
