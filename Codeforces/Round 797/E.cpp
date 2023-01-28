#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	ll ans = 0;
	multiset<ll> m;
	for(int i = 0; i < n; ++i){
		ans += a[i] / k;
		a[i] %= k;
		if(a[i] > 0)
			m.insert(a[i]);
	}
	if(m.size() % 2 == 1)
		m.erase(m.begin());
	while(m.size() >= 2){
		ll u = *m.begin();
		m.erase(m.begin());
		auto v = m.lower_bound(k - u);
		if((u + *v < k) || (v == m.end())){
			m.erase(m.begin());
		}else{
			m.erase(v);
			ans += 1;
		}
	}
	cout << ans << '\n';
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
}