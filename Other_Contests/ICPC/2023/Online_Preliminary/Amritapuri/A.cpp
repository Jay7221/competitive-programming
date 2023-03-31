#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
vector<vector<int>> graph;
vector<int> vis, ans;
int cutoff;
int dfs(int u){
	int sz = 1;
	vis[u] = true;
	for(int v : graph[u]){
		if(!vis[v]){
			sz += dfs(v);
		}
	}
	if(sz >= cutoff){
		ans.push_back(u);
		return 0;
	}
	return sz;
}
void solve(){
	cin >> n >> m;
	graph.assign(n, vector<int>());
	vis.assign(n, false);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cutoff = ceil(sqrt(n));
	dfs(0);
	if((ans.size() < cutoff) && (ans.back() != 0)){
		ans.push_back(0);
	}
	cout << ans.size() << '\n';
	for(int elem : ans){
		++elem;
		cout << elem << ' ';
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
