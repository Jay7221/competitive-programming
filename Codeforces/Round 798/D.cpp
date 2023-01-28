#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, m;
	cin >> n >> m;
	auto dist = [&](pair<int, int>& u, pair<int, int>& v){
		int a, b, x, y;
		tie(a, b) = u;
		tie(x, y) = v;
		return (abs(a - x) + abs(b - y));
	};
	vector<pair<int, int> > black, ext;
	for(int i = 1; i < n + 1; ++i){
		for(int j = 1; j < m + 1; ++j){
			char c;
			cin >> c;
			if(c == 'B'){
				black.push_back({i, j});
			}
		}
	}
	// auto print = [&](pair<int, int>& b){
	// 	int u, v;
	// 	tie(u, v) = b;
	// 	cerr << u << ' ' << v;
	// };
	// auto debug = [&](vector<pair<int, int> > & a){
	// 	for(auto c : a){
	// 		print(c) ;
	// 		cerr << ',';
	// 	}
	// 	cerr << '\n';
	// };
	// auto get = [&](int i, int j){
	// 	pair<int, int> cord = {i, j};
	// 	cerr << cost(cord) << '\n';
	// };
	int u, v;
	tie(u, v) = black[0];
	for(auto c : black){
		int a, b;
		tie(a, b) = c;
		if(a + b < u + v){
			u = a, v = b;
		}
	}
	ext.push_back({u, v});
	for(auto c : black){
		int a, b;
		tie(a, b) = c;
		if(a + b > u + v){
			u = a, v = b;
		}
	}
	ext.push_back({u, v});
	for(auto c : black){
		int a, b;
		tie(a, b) = c;
		if(a - b > u - v){
			u = a, v = b;
		}
	}
	ext.push_back({u, v});
	for(auto c : black){
		int a, b;
		tie(a, b) = c;
		if(a - b < u - v){
			u = a, v = b;
		}
	}
	ext.push_back({u, v});
	auto cost = [&](pair<int, int>& cord){
		int ans = 0;
		for(auto k : ext){
			ans = max(ans, dist(cord, k));
		}
		return ans;
	};
	pair<int, int> ans = {1, 1};
	for(int i = 1; i < n + 1; ++i){
		for(int j = 1; j < m + 1; ++j){
			pair<int, int> cord = {i, j};
			if(cost(cord) < cost(ans)){
				ans = {i, j};
			}
		}
	}
	cout << ans.first << ' ' << ans.second << '\n';
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