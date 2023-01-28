#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll l, r;
	cin >> l >> r;
	auto sq = [&](ll n){
		ll l = 1, r = 1e9 + 7;
		while(l < r){
			ll mid = (l + r + 1) / 2;
			if(mid * mid > n){
				r = mid - 1;
			}else{
				l = mid;
			}
		}
		return l;
	};
	ll tmp = 1e18 + 7;
	ll t1 = sq(l), t2 = sq(r);
	ll ans = 0;
	set<ll> s;
	for(auto dx : {0, 1, 2}){
		s.insert(t1 * t1 + dx * t1);
		s.insert(t2 * t2 + dx * t2);
	}
	for(auto k : s){
		if((k >= l) && (k <= r))
			++ans;
	}
	ans += 3 * max(0ll, t2 - t1 - 1);
	cout << ans << '\n';
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
	return 0;
}