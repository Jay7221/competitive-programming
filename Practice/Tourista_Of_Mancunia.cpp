#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear();	a.resize(n);
int n, m;
vector<int> deg, vis;
vector<pair<int, int> > edges;
vector<multiset<int> > graph;
void dfs(int u){
	while(graph[u].size()){
		int v = *graph[u].begin();
		graph[u].erase(graph[u].find(v));
		graph[v].erase(graph[v].find(u));
		edges.push_back({u, v});
		dfs(v);
	}
}
void connect(int u){
	vis[u] = 1;
	for(auto nei : graph[u]){
		if(!vis[nei])
			connect(nei);
	}
}
void solve(){
	cin >> n >> m;
	prep(graph);
	prep(deg)
	prep(vis)
	if(n == 1 && m == 0){
		cout << "YES\n";
		return ;
	}
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].insert(v);
		graph[v].insert(u);
		++deg[u], ++deg[v];
	}
	for(int i = 0; i < n; ++i){
		if(deg[i] % 2){
			cout << "NO\n";
			return ;
		}
		if(deg[i] == 0){
			cout << "NO\n";
			return ;
		}
	}
	connect(0);
	for(int i = 0; i < n; ++i){
		if(!vis[i]){
			cout << "NO\n";
			return ;
		}
	}
	dfs(0);
	cout << "YES\n";
	for(auto c : edges){
		int u, v;
		tie(u, v) = c;
		++u, ++v;
		cout << u << ' ' << v << '\n';
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}