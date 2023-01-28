#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = 0;
	for(int i = 2; i < n; ++i){
		ans = max(ans, a[i] - a[0] + a[i] - a[i - 1]);
	}
	for(int i = n - 3; i > -1; --i){
		ans = max(ans, a[n - 1] - a[i] + a[i + 1] - a[i]);
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