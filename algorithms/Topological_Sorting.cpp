#include<bits/stdc++.h>
using namespace std;
bool dfs(int u, vector<int>& ans, vector<int>& state, vector<vector<int> >& graph){
	if(state[u] == 1)
		return 0;
	if(state[u] == 2)
		return 1;
	state[u] = 1;
	for(auto v : graph[u]){
		if(!dfs(v, ans, state, graph)){
			return 0 ;
		}
	}
	state[u] = 2;
	ans.push_back(u);
	return 1;
}
bool topological_sort(vector<vector<int> >& graph, vector<int>& ans){
	int n = graph.size();
	vector<int> state(n);
	for(int i = 1; i < n; ++i){
		if(!dfs(i, ans, state, graph)){
			return 0;
		}
	}
	reverse(ans.begin(), ans.end());
	return 1;
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
	vector<int> top_sorted;
	if(topological_sort(graph, top_sorted)){
		for(auto c : top_sorted){
			cerr << c << ' ' ;
		}
		cerr << '\n';
	}else{
		cerr << -1 << '\n';
	}
}