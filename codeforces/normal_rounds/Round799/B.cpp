#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ';}cerr << '\n';
void solve(){
	ll n, q;
	cin >> n >> q;
	vector<ll> p(n);
	for(int i = 0; i < n; ++i){
		cin >> p[i];
	}
	sort(p.rbegin(), p.rend());
	for(ll i = 1; i < n; ++i)
		p[i] += p[i - 1];
	while(q--){
		ll x, y;
		cin >> x >> y;
		y = x - y;
		--x, --y;
		if(y == -1){
			cout << p[x] << '\n';
		}else{
			cout << (p[x] - p[y]) << '\n';
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}