#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int LOGMAX = 32;
const int MAX = (1 << 30);
void solve(){
	auto leastSignificant = [&](ll x){
		for(int i = 0; i < LOGMAX; ++i){
			if((x >> i) & 1){
				return (1 << i);
			}
		}
		return 0;
	};
	int n;
	cin >> n;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	bool flag = true;
	ll ans = 0;
	for(ll k = 1; k <= MAX; k <<= 1){
		ll cur = 0;
		vector<ll> vv;
		for(auto elem : v){
			if(elem & k){
				ans += k;
				cur = (cur | elem);
			}else{
				vv.push_back(elem);
			}
		}
		if(cur){
			ans -= k;
			vv.push_back(cur);
		}
		v = vv;
	}
	if(v.size() == 1){
		cout << ans << '\n';
	}else{
		cout << -1 << '\n';
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