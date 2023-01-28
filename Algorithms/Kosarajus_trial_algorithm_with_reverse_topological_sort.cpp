#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
void dfs1(int u, vector<vector<int> >& graph, vector<bool>& vis, vector<int>& order){
	vis[u] = 1;
	for(auto v : graph[u]){
		if(!vis[v]){
			dfs1(v, graph, vis, order);
		}
	}
	order.push_back(u);
}
void dfs2(int u, vector<vector<int> >& graph, vector<bool>& vis, vector<int>& component){
	vis[u] = 1;
	component.push_back(u);
	for(auto v : graph[u]){
		if(!vis[v]){
			dfs2(v, graph, vis, component);
		}
	}
}
vector<vector<int> > get_components(vector<vector<int> >& graph){
	int n = graph.size();
	vector<int> order;
	vector<bool> vis(n);
	for(int i = 1; i < n; ++i){
		if(!vis[i]){
			dfs1(i, graph, vis, order);
		}
	}
	for(int i = 1; i < n; ++i)
		vis[i] = 0;
	vector<vector<int> > components;
	for(auto u : order){
		if(!vis[u]){
			vector<int> component;
			dfs2(u, graph, vis, component);
			components.push_back(component);
		}
	}
	return components;
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
	vector<vector<int> > components = get_components(graph);
	for(auto component : components){
		for(auto u : component){
			cerr << u << ' ';
		}
		cerr << '\n';
	}
}