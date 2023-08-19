#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n), na(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	set<int> in_a, not_a;
	for(int i = 1; i <= 2 * n; ++i)
		not_a.insert(i);
	for(int i = 0; i < n; ++i){
		in_a.insert(a[i]);
		not_a.erase(a[i]);
	}
	int ind = 0;
	for(auto k : not_a){
		na[ind++] = k;
	}
	ind = 0;
	for(auto k : in_a){
		a[ind++] = k;
	}
	ll ans = 0, tmp = 0;
	int mx = *max_element(a.begin(), a.end());
	for(int i = 0; i < k; ++i){
		mx = max(mx, na[i]);
		tmp += mx - na[i];
	}
	ans = max(ans, tmp);

	tmp = 0;
	mx = na[n - 1];
	for(int i = 0; i < k - 1; ++i){
		tmp += mx - na[i];
	}
	ans = max(ans, tmp);

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