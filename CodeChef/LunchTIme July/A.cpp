#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 1; i < n; ++i){
		a[i] += a[i - 1];
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] < n){
			ans = max(ans, i + 1);
		}
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