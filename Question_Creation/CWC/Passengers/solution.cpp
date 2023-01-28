#include<bits/stdc++.h>
using namespace std;
int N = 1e5;
int LOGMAX = 20;
vector<vector<pair<int, int> > > graph;
vector<vector<int> > lca, dp;
void dfs(int u){
	for(auto [v, w] : tree[u]){
		if(v == lca[u][0])
			continue ;
		lca[v][0] = u;
		dp[v][0] = w;
		dfs(v, u);
	}
}
void pre(){
	for(int k = 0; k < LOGMAX; ++k){
		for(int i = 0; i < n; ++i){
			lca[i][k] = lca[lca[i][k - 1]][k - 1];
			dp[i][k] = min(dp[i][k - 1], dp[lca[i][k - 1]][k - 1]);
		}
	}
}
void solve(){
	cin >> n;
	lca.clear(), dp.clear();
	lca.resize(n, vector<int>(LOGMAX));
	dp.resize(n, vector<int>(LOGMAX, INF));
	for(int i = 0; i < n; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		tree[u].push_back({v, w});
		tree[v].push_back({u, w});
	}
	lca[0][0] = 0;
	dfs(0, 0);
	pre();
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
