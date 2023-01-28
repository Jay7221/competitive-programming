#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){ cerr << c << ' ' ; } cerr << '\n';
#define ll long long
void solve(){
	ll n, m;
	ll ans = 0;
	cin >> n >> m;
	vector<ll> a(m);
	for(ll i = 0; i < m; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<ll> blocks;
	// blocks -> sizes of uninfected blocks
	ll k = a.size();
	if(k > 1){
		ll x = n - (a[m - 1] - a[0] + 1);
		if(x > 0){
			blocks.push_back(x);
		}
	}
	if(k == 1){
		ll ans = max(0ll, n - 2);
		ans = n - ans;
		cout << ans << '\n';
		return ;
	}
	for(ll i = 0; i < k - 1; ++i){
		ll x = a[i + 1] - a[i] - 1;
		if(x > 0){
			blocks.push_back(x);
		}
	}
	ll tmp = 0;
	sort(blocks.rbegin(), blocks.rend());
	for(ll i = 0; i < blocks.size(); ++i){
		ll x = blocks[i] - tmp;
		if(x > 2){
			ans += x - 1;
			tmp += 4;
		}else if(x == 2 || x == 1){
			ans += 1;
			tmp += 2;
		}else{
			break;
		}
	}
	ans = n - ans;
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