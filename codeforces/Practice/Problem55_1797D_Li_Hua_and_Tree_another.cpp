#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<set<pair<ll, int>>> tree;
vector<vector<int>> graph;
vector<ll> dp;
vector<int> par, subtree;
void dfs(int u, int p){
	par[u] = p;
	for(int v : graph[u]){
		if(v != par[u]){
			dfs(v, u);
			subtree[u] += subtree[v];
			dp[u] += dp[v];
		}
	}
}
void solve(){
	int n, m;
	cin >> n >> m;
	tree.assign(n, set<pair<ll, int>>());
	graph.assign(n, vector<int>());
	dp.assign(n, 0);
	par.assign(n, -1);
	subtree.assign(n, 1);
	for(int i = 0; i < n; ++i){
		cin >> dp[i];
	}
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, -1);
	for(int u = 0; u < n; ++u){
		for(int v : graph[u]){
			if(v != par[u]){
				tree[u].insert({-subtree[v], v});
			}
		}
	}
	auto remove_edge = [&](int u, int v){
		tree[u].erase({-subtree[v], v});
		par[v] = -1;
		dp[u] -= dp[v];
		subtree[u] -= subtree[v];
	};
	auto add_edge = [&](int u, int v){
		par[v] = u;
		dp[u] += dp[v];
		subtree[u] += subtree[v];
		tree[u].insert({-subtree[v], v});
	};
	auto get_heavy_son = [&](int u){
		int s, simp;
		tie(simp, s) = *tree[u].begin();
		return s;
	};
	auto swap = [&](int u){
		if((par[u] != -1) && (tree[u].size() > 0)){
			int p = par[u];
			int s = get_heavy_son(u);
			// cerr << dp[p] << ' ' << dp[u] << ' ' << dp[s] << '\n';
			remove_edge(p, u);
			remove_edge(u, s);
			add_edge(s, u);	
			add_edge(p, s);
			// cerr << dp[p] << ' ' << dp[u] << ' ' << dp[s] << '\n';
		}
		return;
	};
	for(int i = 0; i < m; ++i){
		int t, x;
		cin >> t >> x;
		--x;
		if(t == 1){
			cout << dp[x] << '\n';
		}else{
			swap(x);
		}
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}
