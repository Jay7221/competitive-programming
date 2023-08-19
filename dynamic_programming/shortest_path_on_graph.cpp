#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define inf (int)(1e9 + 7)
#define prep(a) a.clear();	a.resize(n);
#define debug(a) for(auto c : a){cerr <<  c << ' ';}cerr << '\n';
vector<vector<int>> graph;
vector<int> dp, backlink;
void dfs(int u){
	for(auto nei : graph[u]){
		if(dp[nei] > dp[u] + 1){
			dp[nei] = dp[u] + 1;
			backlink[nei] = u;
			dfs(nei);
		}
	}
}
void solve(){
	int n, m;
	cin >> n >> m;
	prep(graph)
	prep(dp)
	prep(backlink)
	for(int i= 0; i < n; ++i)
		dp[i] = inf;
	dp[0] = 0;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0);
	cout << dp[n - 1] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}