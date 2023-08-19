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
	if(k > n){
		cout << -1 << '\n';
		return ;
	}
	ll ans = accumulate(a.begin(), a.end(), 0ll);
	ll cur = 0;
	ll sum = (accumulate(a.begin(), a.end(), 0ll) + k - 1) / k;
	for(int i = 0, j = 0; j < n; ++j){
		cur += a[j];
		if(cur >= sum){
			ans = min(ans, cur);
			cur -= a[i];
			++i;
		}
	}
	ans = max(ans, *max_element(a.begin(), a.end()));
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