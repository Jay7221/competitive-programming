#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<vector<int> > graph(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<int> sz(n + 1, 0);
	vector<int> par(n + 1, 0);


	auto dfs_sz = [&](auto &self, int u) -> void {
		sz[u] = 1;
		for(int v : graph[u]){
			if(v != par[u]){
				par[v] = u;
				self(self, v);
				sz[u] += sz[v];
			}
		}
	};

	int centroid = 1;
	dfs_sz(dfs_sz, centroid);
	for(int i = 1; i <= n; ++i){
		int mx = n - sz[i];
		for(int v : graph[i]){
			if(v != par[i]){
				mx = max(mx, sz[v]);
			}
		}
		if(mx <= n / 2){
			centroid = i;
		}
	}


	vector<int> order;
	auto dfs_order = [&](auto &self, int u, int p) -> void {
		if(u == centroid){
			sort(graph[u].begin(), graph[u].end(),
				[&](int x, int y){
					int v = (par[u] == x) ? (n - sz[u]) : sz[x];
					int w = (par[u] == y) ? (n - sz[u]) : sz[y];
					return (v > w);
				});
		}
		for(int v : graph[u]){
			if(v != p){
				self(self, v, u);
			}
		}
		order.push_back(u);
	};

	dfs_order(dfs_order, centroid, -1);

	vector<int> ans(n);
	int pos = 0;
	for(int i = 0; i < n; ++i){
		ans[pos] = order[i];
		pos += 2;
		if(pos >= n){
			pos = 1;
		}
	}

	cout << centroid << '\n';
	for(int v : ans){
		cout << v << ' ';
	}
	cout << '\n';
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
