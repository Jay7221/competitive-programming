#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i < n; ++i)
		a[i] += a[i - 1];
	ll sum = a[n - 1];
	int ans = n;
	auto check = [&](ll k){
		ll cur = k;
		int ans = 0, prev = -1;
		for(int i = 0; i < n; ++i){
			if(a[i] == cur){
				ans = max(ans, i - prev);
				prev = i;
				cur += k;
			}
		}
		if(cur != (a[n - 1] + k))
			return INF;
		else
			return ans;
	};
	for(ll i = 1; i <= sqrt(sum); ++i){
		if(sum % i)
			continue ;
		ans = min(ans, check(i));
		ans = min(ans, check(sum / i));
	}
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