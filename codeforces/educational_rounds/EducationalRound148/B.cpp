#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<ll> pre = a;
	for(int i = 1; i < n; ++i){
		pre[i] += pre[i - 1];
	}
	auto get = [&](int l, int r){
		ll ans = pre[r];
		if(l > 0){
			ans -= pre[l - 1];
		}
		return ans;
	};
	int l = 0, r = n - 1 - k;
	ll ans = get(l, r);
	while(r < n){
		ans = max(ans, get(l, r));
		l += 2;
		++r;
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