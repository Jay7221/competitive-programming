#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear(); 	a.resize(n);
vector<vector<int> > graph;
set<pair<int, int> > ans;
vector<int> deg;
int n, m;
void dfs(int u){
	for(auto nei : graph[u]){
		if(deg[nei] == 0)
			continue ;
		else if(deg[nei] % 2 == 1)
	}
}
void solve(){
	cin >> n >> m;
	prep(graph);
	prep(deg)
	for(int i = 0; i < n; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		++deg[u], ++deg[v];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 0; i < n; ++i){
		if((deg[i] % 2 == 1) || deg[i] == 0){
			cout << -1 << '\n';
			return ;
		}
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