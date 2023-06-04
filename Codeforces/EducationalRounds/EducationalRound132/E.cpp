#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<vector<int> > graph;
vector<set<int> > vals;
void dfs(int u, int p){
	
}
void solve(){
	cin >> n;
	a.clear();
	a.resize(n + 1);
	for(int i = 1; i < n + 1; ++i){
		cin >> a[i];
	}
	graph.clear();
	graph.resize(n + 1);
	vals.resize(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1, 0);
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}