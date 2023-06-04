#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<pair<ll, ll>> v(n);
	for(int i = 0; i < n; ++i){
		ll a, b;
		cin >> a >> b;
		v[i] = {a, b};
	}	
	auto check = [&](ll h, ll w){
		map<ll, multiset<ll>> x, y;
		for(auto [a, b] : v){
			x[a].insert(b);
			y[b].insert(a);
		}
		auto erase = [&](ll a, ll b){
			x[a].erase(x[a].find(b));
			y[b].erase(y[b].find(a));
		};
		while((h > 0) && (w > 0)){
			if(x[h].size()){
				ll a = h;
				ll b = *x[h].begin();
				erase(a, b);
				w -= b;
				continue;
			}
			if(y[w].size()){	
				ll b = w;
				ll a = *y[w].begin();
				erase(a, b);
				h -= a;
				continue;
			}
			return false;
		}
		return true;
	};
	
	ll area = 0;
	ll h = 0, w = 0;
	for(auto [a, b] : v){
		area += a * b;
		h = max(h, a);
		w = max(w, b);
	}

	set<pair<ll, ll>> ans;

	if((area % h == 0) && check(h, area / h)){
		ans.insert({h, area / h});
	}
	if((area % w == 0) && check(area / w, w)){
		ans.insert({area / w, w});
	}
	cout << ans.size() << "\n";
	for(auto [h, w] : ans){
		cout << h << ' ' << w << '\n';
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
