#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
ll INF = 1000000000000000007;
ll S(ll N){
	ll l = 0;
	ll r = 10000000007;
	while(l < r){
		ll m = (l + r + 1) / 2;
		if((m * m) <= N){
			l = m;
		}else{
			r = m - 1;
		}
	}
	return l;
}
ll C(ll N){
	ll l = 0;
	ll r = 1000007;
	while(l < r){
		ll m = (l + r + 1) / 2;
		if((m * m * m) <= N){
			l = m;
		}else{
			r = m - 1;
		}
	}
	return l;
}
ll F(ll N){
	return (S(N) - C(N));
}
void solve(){
	ll x;
	cin >> x;
	ll l = 0, r = INF;
	while(l < r){
		ll mid = (l + r) / 2;
		if(F(mid) >= x){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	cout << l << '\n';
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
