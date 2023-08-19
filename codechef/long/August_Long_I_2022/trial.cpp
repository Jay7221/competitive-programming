#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e9 + 7;
void solve(){
	ll n, s;
	cin >> n >> s;
	auto check_2 = [&](ll mx_elem){
		ll span = n - 1;
		ll mx_sum = 0;
		ll cnt = 0;
		for(int k = 31; k > -1; --k){
			if(1 & (mx_elem >> k)){
				mx_sum += (n - 1) * (1 << k);
				++cnt;
				cnt = min(cnt, n - 1);
			}else{
				mx_sum += cnt * (1 << k);
			}
		}
		return mx_sum >= s;
	};
	auto check = [&](ll mx_elem){
		ll mx_sum = 0;
		ll span = n - 1, lag = 0;
		for(int k = log2(mx_elem); k > -1; --k){
			if(1 & (mx_elem >> k)){
				mx_sum += (n - 1) * (1 << k);
				span = max(0ll, span - 1);
				lag = min(lag + 1, n - 1);
			}else{
				mx_sum += (n - 1 - span) * (1 << k);
			}
		}
		return mx_sum >= s;
	};
	ll l = 1, r = MAX;
	while(l < r){
		ll mid = (l + r) / 2;
		if(check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}