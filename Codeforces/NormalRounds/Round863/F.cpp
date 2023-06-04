#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> graph;
int n, m;
void dfs(int u, vector<bool> &vis){
	vis[u] = true;
	for(int v : graph[u]){
		if(!vis[v]){
			dfs(v, vis);
		}
	}
}
bool is_connected(){
	vector<bool> vis(n);
	dfs(0, vis);
	for(int i = 0; i < n; ++i){
		if(!vis[i]){
			return false;
		}
	}
	return true;
}
bool solve(){
	cin >> n >> m;
	graph.assign(n, vector<int>());
	vector<int> d(n);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		++d[u], ++d[v];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int k = m - n;
	if(k * k != n){
		return false;
	}
	if(!is_connected()){
		return false;
	}
	int cnt2 = 0, cnt4 = 0;
	for(int i = 0; i < n; ++i){
		cnt2 += (d[i] == 2);
		cnt4 += (d[i] == 4);
	}
	if((cnt2 == k * (k - 1)) && (cnt4 == k)){
		return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		if(solve()){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}

	return 0;
}
