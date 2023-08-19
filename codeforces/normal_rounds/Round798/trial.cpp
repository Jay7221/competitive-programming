#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear();	a.resize(n);
vector<vector<int> > graph;
vector<int> a, dp1, dp2;
int gcd(int a, int b){
	while(b){
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
void dfs(int u, int p = -1){
	dp1[u] = u;
	par[u] = p;
	for(auto child : graph[u]){
		if(child == par[u])
			continue ;
		dfs(child, u);
		dp1[u] = gcd(dp1[u], dp1[child]);
	}
}
void dfs2(int u){
	dp2[u] = 0;
	for(auto child : graph[u]){
		if(child == par[u])
			continue ;
		dp2[u] += dp1[child];
		dfs2(child);
	}
}
void solve(){
	cin >> n;
	prep(graph)
	prep(a)
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
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