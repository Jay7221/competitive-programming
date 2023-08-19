#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	vector<tuple<ll, ll, ll> > v(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i];
		v[i] = {a[i] - b[i], a[i], b[i]};
	}
	sort(v.rbegin(), v.rend());
	auto check = [&](ll m){
		for(auto [x, y, z] : v){
			if(m < y)
				return false;
			m -= z;
		}
		return true;
	};
	ll l = 1, r = 1e9 + 7;
	while(l < r){
		ll m = (l + r) / 2;
		if(check(m))
			r = m;
		else
			l = m + 1;
	}
	cout << l << '\n';
}