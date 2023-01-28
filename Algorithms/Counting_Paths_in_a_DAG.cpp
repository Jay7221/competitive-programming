#include<bits/stdc++.h>
using namespace std;
void dfs(int u, vector<vector<int> >& graph, vector<bool>& vis, vector<int>& top_sorted){
	if(vis[u])
		return ;
	vis[u] = 1;
	for(auto v : graph[u])
		dfs(v, graph, vis, top_sorted);
	top_sorted.push_back(u);
}
vector<int> count_paths(vector<vector<int> >& graph){
	int n = graph.size();
	vector<int> dp(n);
	dp[1] = 1;
	// dp[i] = number of paths from node 1 to node i
	vector<int> top_sorted;
	// top_sorted -> contains nodes in topological sorted order
	vector<bool> vis(n);
	for(int i = 1; i < n; ++i){
		dfs(i, graph, vis, top_sorted);
	}
	reverse(top_sorted.begin(), top_sorted.end());
	for(auto c : top_sorted){
		for(auto v : graph[c]){
			dp[v] += dp[c];
		}
	}
	return dp;
}
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	vector<int> distances = count_paths(graph);
	for(int i = 1; i < n + 1; ++i){
		cerr << distances[i] << ' ' ;
	}
	cerr << '\n';
}