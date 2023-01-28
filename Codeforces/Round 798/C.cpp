#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear();	a.resize(n);
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
vector<set<int> > graph;
vector<int> dp, sz;
int n;
void dfs(int u, int p = -1){
	graph[u].erase(p);
	for(auto child : graph[u]){
		dfs(child, u);
	}
	int a, b;
	if(graph[u].size() == 0)
		return ;
	else if(graph[u].size() == 1){
		a = *graph[u].begin();
		dp[u] = sz[a];
		sz[u] = 1 + sz[a];
	}else{
		a = *graph[u].begin();
		b = *(++graph[u].begin());
		sz[u] = 2 + sz[a] + sz[b];
		dp[u] = max(dp[a] + sz[b], sz[a] + dp[b]);
	}
}
void solve(){
	cin >> n;
	prep(dp)
	prep(graph)
	prep(sz)
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].insert(v);
		graph[v].insert(u);
	}
	dfs(0);
	cout << dp[0] << '\n';
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