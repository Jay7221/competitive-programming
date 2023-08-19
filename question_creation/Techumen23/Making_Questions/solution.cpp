#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;
	cin >> n;
	ll t[4];
	for(int i = 0; i < 4; ++i){
		cin >> t[i];
	}
	ll l = 0, r = 1e18;
	auto check = [&](ll time){
		ll no_q = 0;
		for(int i = 0; i < 4; ++i){
			no_q += time / t[i];
		}
		return (no_q >= n);
	};
	while(l < r){
		ll m = (l + r) / 2;
		if(check(m)){
			r = m;
		}else{
			l = m + 1;
		}
	}
	for(int i = 0; i < 4; ++i){
		if(l % t[i] == 0){
			cout << i + 1 << '\n';
			return;
		}
	}
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
