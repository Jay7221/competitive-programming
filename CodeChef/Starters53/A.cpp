#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	if(accumulate(a.begin(), a.end(), 0ll) != accumulate(b.begin(), b.end(), 0ll)){
		cout << -1 << '\n';
		return ;
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ans += abs(a[i] - b[i]);
	}
	if(ans % 2){
		cout << -1 << '\n';
		return ;
	}
	cout << ans / 2 << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}