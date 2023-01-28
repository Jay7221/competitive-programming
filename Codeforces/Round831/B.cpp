#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> arr(n);
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ll a, b;
		cin >> a >> b;
		ans += 2 * (a + b);
		arr[i] = max(a, b);
	}
	sort(arr.begin(), arr.end());
	for(int i = 0; i < n - 1; ++i){
		ans -= 2 * arr[i];
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