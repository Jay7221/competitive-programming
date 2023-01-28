#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	map<ll, ll> freq;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		++freq[a];
	}
	vector<ll> v;
	v.push_back(0);
	for(auto [a, f] : freq)
		v.push_back(f);
	v.push_back(0);
	ll ans = 0;
	vector<ll> pre = v;
	for(int i = 1; i < pre.size(); ++i)
		pre[i] += pre[i - 1];
	for(int i = 1; i < v.size() - 1; ++i){
		ll left = pre[i - 1], right = n - pre[i];
		ll tmp = left * right + max({v[i] * left, v[i] * right, v[i] / 2});
		ans = max(ans, tmp);
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