#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> graph;
vector<int> com;
vector<bool> vis;
int cur = 0;
void dfs(int u){
	vis[u] = true;
	for(int v : graph[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}
void solve(){
	int n, m, q, s;
	cin >> n >> m >> q >> s;
	graph.assign(n, vector<int>());
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	vis.assign(n, false);
	dfs(s);
	for(int i = 0; i < q; ++i){
		int d;
		cin >> d;
		if(vis[d]){
			cout << "Possible\n";
		}else{
			cout << "ImPossible\n";
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
