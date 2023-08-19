#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	for(int i = 0; i <= n / 2; ++i){
		ll mn = min(v[i], v[n - 1 - i]);
		v[i] -= mn;
		if(2 * i != n - 1){
			v[n - 1 - i] -= mn;
		}
	}
	ll ans = v[0];
	for(int i = 1; i < n; ++i)
		ans += max(0ll, v[i] - v[i - 1]);
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