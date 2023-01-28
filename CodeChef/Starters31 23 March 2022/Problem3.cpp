#include<bits/stdc++.h>
using namespace std;
#define ll long long
int max_pow(ll n){
	int ans = 0;
	ll k = 1;
	while(k <= n){
		k = k << 1;
		ans++;
	}
	ans--;
	return ans;
}
void solve(){
	ll n;
	cin >> n;
	int k = max_pow(n);
	ll ans = 0;
	for(int i = 0; i < k; i++){
		ans += pow(2, i) - 1;
	}
	ll t = pow(2, k);
	n = n - t;
	ans += n;
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}