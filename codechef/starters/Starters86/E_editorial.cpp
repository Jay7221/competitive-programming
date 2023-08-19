#include "bits/stdc++.h"
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector adj(n+1, vector<int> ());
		for (int i = 0; i < n-1; ++i) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector subsz(n+1, 0), par(n+1, 0);
		vector<int> order, ans(n);
		int centroid = 1;
		
		auto dfs_sz = [&] (const auto &self, int u) -> void {
			subsz[u] = 1;
			for (int v : adj[u]) {
				if (v == par[u]) continue;
				par[v] = u;
				self(self, v);
				subsz[u] += subsz[v];
			}
		};
		auto dfs_order = [&] (const auto &self, int u, int p) -> void {
			if (u == centroid) sort(begin(adj[u]), end(adj[u]), [&] (int x, int y) { // Sorting subtrees by size
				int v = x == par[u] ? n - subsz[u] : subsz[x];
				int w = y == par[u] ? n - subsz[u] : subsz[y];
				return v > w;
			});

			for (int v : adj[u]) {
				if (v == p) continue;
				self(self, v, u);
			}
			order.push_back(u);
		};

		dfs_sz(dfs_sz, 1);
		for (int i = 1; i <= n; ++i) {
			int mx = n - subsz[i];
			for (int v : adj[i]) {
				if (v == par[i]) continue;
				mx = max(mx, subsz[v]);
			}
			if (mx <= n/2) centroid = i;
		}
		cout << centroid << '\n';
		dfs_order(dfs_order, centroid, -1);
		int pos = 0;
		for (int x : order) {
		    ans[pos] = x;
		    pos += 2;
		    if (pos >= n) pos = 1;
		}
		for (int x : ans) cout << x << ' ';
		cout << '\n';
	}
}