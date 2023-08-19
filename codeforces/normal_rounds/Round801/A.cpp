#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define inf (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
#define debug1(a) for(auto c : a){debug(c)} cerr << "------------------------------\n";
void solve(){
	int n, m;
	cin >> n >> m;
	int ans = n * m;
	int mx = -inf;
	vector<vector<int> > g(n, vector<int>(m)), dp(n, vector<int>(m, n * n));
	vector<vector<int> > h(n, vector<int>(m, n)), k(n, vector<int>(m, m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> g[i][j];
			mx = max(mx, g[i][j]);
		}
	}
	vector<pair<int, int> > a;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(g[i][j] == mx){
				a.push_back({i, j});
			}
		}
	}
	auto update = [&](int h, int k){
		vector<vector<bool> > vis(n, vector<bool>(m, 0));
		for(auto c : a){
			int x, y ;
			tie(x, y) = c;
			for(int i = max(0, x - h); i < min(n, x + h + 1); ++i){
				for(int j = max(0, y - k); j < min(m, y + k + 1); ++j){
					vis[i][j] = 1;
				}
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(vis[i][j])
					continue ;
				return ;
			}
		}
		ans = min(ans, (h + 1) * (k + 1));
	};
	for(int h = 0; h < n; ++h){
		for(int k = 0; k < m; ++k){
			update(h, k);
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