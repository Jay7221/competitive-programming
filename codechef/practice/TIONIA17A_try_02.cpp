#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto m : a){for(auto n : m){cerr << n << ' ';} cerr << '\n';} cerr << '\n';
vector<pair<ll, ll> > d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
ll total_len(ll i, ll j, map<pair<int, int>, ll>& len, map<pair<int, int>, bool>& Map){
		ll ans = len[{i, j}];
		Map[{i, j}] = 0;
		queue<pair<ll, ll> > next;
		next.push({i, j});
		while(!next.empty()){
			ll x, y;
			tie(x, y) = next.front();
			next.pop();
			for(auto c : d){
				ll xx = x + c.first, yy = y + c.second;
				if(Map[{xx, yy}] == 1){
					Map[{xx, yy}] = 0;
					ans += len[{xx, yy}];
					next.push({xx, yy});
				}
			}
		}
		// debug(Map)
		return ans;
	}
void solve(){
	ll r, c, n;
	cin >> r >> c >> n;
	map<pair<int, int>, bool> Map;
	vector<pair<int, int> > cultivated(n);
	for(ll i = 0; i < n; i++){
		ll x, y;
		cin >> x >> y;
		Map[{x, y}] = 1;
		cultivated[i] = {x, y};
	}
	map<pair<int, int>, ll> len;
	for(auto c : cultivated){
		int i = c.first, j = c.second;
		for(auto k : d){
			ll di, dj;
			tie(di, dj) = k;
			len[{i, j}] += (1 ^ Map[{i + di, j + dj}]);
		}
	}
	ll ans = 0;
	// debug(Map)
	// debug(len)
	for(auto c : cultivated){
		int i = c.first, j = c.second;
		ans = max(ans, total_len(i, j, len, Map));
	}

	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	t = 1;
	while(t--){
		solve();
	}
}