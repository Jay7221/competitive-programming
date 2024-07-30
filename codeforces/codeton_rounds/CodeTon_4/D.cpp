#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	const ll INF = 1e18 + 7;
	int q;
	cin >> q;
	ll hl = 0, hr = INF;
	auto get_l = [&](ll a, ll b, ll n){
		if(n == 0){
			return 0ll;
		}
		if(n == 1){
			return 1ll;
		}
		ll ans = a * (n - 1) - b * (n - 2) + 1;
		return ans;
	};
	auto get_r = [&](ll a, ll b, ll n){
		if(n == 0){
			return 0ll;
		}
		ll ans = a * n - b * (n - 1);
		return ans;
	};
	auto find_l = [&](ll a, ll b){
		ll l = 0, r = INF;
		while(l < r){
			ll m = (l + r) / 2;
			if(get_r(a, b, m) >= hl){
				r = m;
			}else{
				l = m + 1;
			}
		}
		return l;
	};
	auto find_r = [&](ll a, ll b){
		ll l = 0, r = INF;
		while(l < r){
			ll m = (l + r + 1) / 2;
			if(get_l(a, b, m) <= hr){
				l = m;
			}else{
				r = m - 1;
			}
		}
		return l;
	};
	vector<ll> v(q);
	for(int i = 0; i < q; ++i){
		int type;
		cin >> type;
		if(type == 1){
			ll a, b, n;
			cin >> a >> b >> n;
			ll l = get_l(a, b, n);
			ll r = get_r(a, b, n);
			if((r < hl) || (hr < l)){
				v[i] = 0;
			}else{
				v[i] = 1;
				hl = max(hl, l);
				hr = min(hr, r);
			}
		}else{
			ll a, b;
			cin >> a >> b;
			// cerr << a << ' ' << b << ' ' << find_l(a, b) << ' ' << find_r(a, b) << '\n';
			if(find_l(a, b) == find_r(a, b)){
				v[i] = find_l(a, b);
			}else{
				v[i] = -1;
			}
		}
	}
	for(ll elem : v){
		cout << elem << ' ' ;
	}
	cout << '\n';
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
