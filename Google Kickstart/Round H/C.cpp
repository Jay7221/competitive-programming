#include<bits/stdc++.h>
using namespace std;
#define prep(a) a.clear();	a.resize(n);
int n;
vector<vector<int> > tree;
vector<int> a, dp;
vector<bool> vis;
void dfs1(int u){
	vis[u] = 1;
	for(auto v : tree[u]){
		if(!vis[v]){
			dfs1(v);
			if(a[v] < a[u])
				dp[u] += dp[v];
		}
	}
	vis[u] = 0;
}
void dfs2(int u){
	vis[u] = 1;
	for(auto v : tree[u]){
		if(!vis[v]){
			if(a[u] < a[v]){
				dp[v] += dp[u];
			}
			dfs2(v);
		}
	}
	vis[u] = 0;
}
void solve(){
	cin >> n;
	prep(tree)
	prep(a)
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dp.clear();
	dp.resize(n, 1);
	prep(vis)
	dfs1(0);
	dfs2(0);
	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << '\n';
}
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}