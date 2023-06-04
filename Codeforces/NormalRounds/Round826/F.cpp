#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e18 + 7;
void solve(){
	int n;
	cin >> n;
	vector<vector<tuple<ll, ll, ll> > > points(n + 1);
	multiset<ll> m, L, R;
	m.insert(-MAX);
	m.insert(MAX);
	L = R = m;
	for(int i = 1; i <= n; ++i){
		ll l, r, c;
		cin >> l >> r >> c;
		tuple<ll, ll, ll> tmp = {l, r, i};
		m.insert(l);
		m.insert(r);
		L.insert(l);
		R.insert(r);
		points[c].push_back(tmp);
	}
	vector<ll> ans(n + 1);
	auto calc = [&](ll k){
		ll p, q;
		p = *(--m.lower_bound(k));
		q = *m.lower_bound(k);
		ll ans = min(abs(p - k), abs(q - k));
		
		return ans;
	};
	for(int i = 1; i <= n; ++i){
		for(auto [l, r, i] : points[i]){
			m.erase(m.find(l));
			m.erase(m.find(r));
			L.erase(L.find(l));
			R.erase(R.find(r));
		}

		for(auto [l, r, i] : points[i]){
			ans[i] = calc(l, r);
		}

		for(auto [l, r, i] : points[i]){
			m.insert(l);
			m.insert(r);
			L.insert(l);
			R.insert(r);
		}
	}

	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ' ;
	cout << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}