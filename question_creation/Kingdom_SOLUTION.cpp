#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define pre(a) a.clear();	a.resize(n);
vector<vector<int> > graph;
ll ans, cur_loot;
vector<ll> loot;
vector<bool> visited;
dfs(int u){
	visited[u] = 1;
	cur_loot += loot[u];
	ans = max(ans, cur_loot);
	for(auto c : graph[u]){
		if(!visited[c])
			dfs(c);
	}
	cur_loot -= loot[u];
	visited[u] = 0;
}
void solve(){
	int n, m;
	cin >> n >> m;
	pre(graph)
	pre(loot)
	pre(visited)
	for(int i = 0; i < n; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 0; i < n; ++i){
		cin >> loot[i];
	}
	ans = 0;
	dfs(0);
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