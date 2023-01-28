#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	ll ans = 0;
	int ind = 0;
	while(ind < n && a[ind] == 0){
		++ind;
	}
	for(int i = ind; i < n - 1; ++i){
		ans += max(a[i], 1ll);
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}