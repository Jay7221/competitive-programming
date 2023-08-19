#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;
	cin >> n;
	ll a[n];
	map<ll, ll> even, odd;
	ll nodd = 0, neven = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] % 2){
			odd[a[i] / 4]++;
			nodd++;
		}
		else{
			even[a[i] / 4]++;
			neven++;
		}
	}
	ll ans = nodd * (nodd - 1) / 2 + neven * (neven - 1 ) / 2 ;
	for(auto c : odd){
		ll k = c.second;
		ans -= k * (k - 1) / 2;
	}
	for(auto c : even){
		ll k = c.second;
		ans -= k * (k - 1) / 2;
	}
	cout << ans  << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}