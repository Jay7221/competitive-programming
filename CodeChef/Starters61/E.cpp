#include<bits/stdc++.h>
using namespace std;
#define ti tuple<int, int, int>
#define pi pair<int, int>
const int INF = 1e9 + 7;
void solve(){
	int n, m;
	cin >> n >> m;
	map<ti, vector<pair<int, ti>>> graph;
	map<pi, bool> grid;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			char ch;
			cin >> ch;
			if(ch == '.')
				grid[{i, j}] = 1;
		}
	}
	auto check = [&](int i, int j, int k){
		if((i > 0) && (j > 0) && (i <= n) && (j <= m)){
			if(grid[{i, j}] || k)
				return true;
		}
		return false;
	};
	vector<pair<int, ti> > d0 = {
		{0, {0, -1, 0}}, {0, {0, 1, 0}}, {1, {0, -1, 1}}, {1, {0, 1, 1}},
		{0, {-1, 0, 0}}, {0, {1, 0, 0}}, {1, {-1, 0, 1}}, {1, {1, 0, 1}}
	};
	vector<pair<int, ti> > d1 = {
		{0, {0, -1, 1}}, {0, {0, 1, 1}},
		{0, {-1, 0, 0}}, {0, {1, 0, 0}}, {1, {-1, 0, 1}}, {1, {1, 0, 1}}
	};
	for(int x = 1; x <= n; ++x){
		for(int y = 1; y <= m; ++y){
			for(auto [wei, nei] : d0){
				int dx, dy, k;
				tie(dx, dy, k) = nei;
				int xx = x + dx, yy = y + dy;
				if(check(xx, yy, k)){
					graph[{x, y, 0}].push_back({wei, {xx, yy, k}});
				}
			}
			for(auto [wei, nei] : d1){
				int dx, dy, k;
				tie(dx, dy, k) = nei;
				int xx = x + dx, yy = y + dy;
				if(check(xx, yy, k)){
					graph[{x, y, 1}].push_back({wei, {xx, yy, k}});
				}
			}
		}
	}
	map<ti, int> dp;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			for(int k = 0; k <= 1; ++k){
				dp[{i, j, k}] = INF;
			}
		}
	}
	dp[{1, 1, 0}] = 0;
	set<pair<int, ti>> s;
	s.insert({0, {1, 1, 0}});
	while(s.size()){
		int dd;
		ti u;
		tie(dd, u) = *s.begin();
		s.erase(s.begin());
		for(auto [w, v] : graph[u]){
			if(dp[v] > dp[u] + w){
				s.erase({dp[v], v});
				dp[v] = dp[u] + w;
				s.insert({dp[v], v});
			}
		}
	}
	cout << min(dp[{n, m, 0}], dp[{n, m, 1}]) << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}