#include<bits/stdc++.h>
using namespace std;
#define ll long long
int left_bit(ll n){
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
	int n;
	cin >> n;
	ll a;
	map<int, int> left_most_set_bits; 
	for(int i = 0; i < n; i++){
		cin >> a;
		left_most_set_bits[left_bit(a)]++;
	}
	ll ans = 0;
	for(auto c : left_most_set_bits){
		int k = c.second;
		ans += (ll)k * (k - 1) / 2;
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}