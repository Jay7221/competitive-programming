#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, m;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> m;
	vector<ll> b(m);
	for(int i = 0; i < m; ++i)
		cin >> b[i];
	ll mx_pre = 0, mx_suf = 0, mx_b = 0;
	ll cur = 0;
	for(int i = 0; i < n; ++i){
		cur += a[i];
		mx_pre = max(mx_pre, cur);
	}
	cur = 0;
	for(int i = n - 1; i > -1; --i){
		cur += a[i];
		mx_suf = max(mx_suf, cur);
	}
	for(int i = 0; i < m; ++i){
		mx_b = max(mx_b, mx_b + b[i]);
	}
	ll ans = mx_b + max(mx_pre, mx_suf);
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