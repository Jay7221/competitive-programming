#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e9 + 7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, M, L;
	cin >> n >> M >> L;
	vector<ll> u(n), a(n);
	for(int i = 0; i < n; ++i)
		cin >> u[i] >> a[i];
	auto check = [&](ll T){
		ll cur = 0;
		for(int i = 0; i < n; ++i){
			ll t = (L - u[i] + a[i] - 1) / a[i];
			ll tmp = (u[i] * (T - t + 1)) + (a[i] * (T - t + 1) * (T + t)) / 2;
			cur += tmp;
			if(cur >= M){
				return true;
			}
		}
		return false;
	};
	ll l = 0, r = INF;
	while(l < r){
		ll m = (l + r) / 2;
		if(check(m)){
			r = m;
		}else{
			l = m + 1;
		}
	}
	cout << l ;
}