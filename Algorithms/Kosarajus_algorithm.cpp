#include<bits/stdc++.h>
using namespace std;
void dfs1(int u, vector<vector<int> >& graph, vector<bool>& vis, vector<int>& order){
	vis[u] = 1;
	for(auto v : graph[u]){
		if(!vis[v]){
			dfs1(v, graph, vis, order);
		}
	}
	order.push_back(u);
}
void dfs2(int u, vector<vector<int> >& rev_graph, vector<bool>& vis, vector<int>& component){
	component.push_back(u);
	vis[u] = 1;
	for(auto v : rev_graph[u]){
		if(!vis[v]){
			dfs2(v, rev_graph, vis, component);
		}
	}
}
vector<vector<int> > get_components(vector<vector<int> >& graph){
	int n = graph.size();
	vector<bool> vis(n);
	vector<int> order;
	for(int i = 1; i < n; ++i){
		if(!vis[i]){
			dfs1(i, graph, vis, order);
		}
	}
	reverse(order.begin(), order.end());
	// in a way this is topologically sorted nodes
	for(int i = 1; i < n; ++i){
		vis[i] = 0;
	}
	vector<vector<int> > rev_graph(n);
	for(int i = 1; i < n; ++i){
		for(auto v : graph[i]){
			rev_graph[v].push_back(i);
		}
	}
	vector<vector<int> > components;
	for(auto c : order){
		if(!vis[c]){
			vector<int> component;
			dfs2(c, rev_graph, vis, component);
			components.push_back(component);
		}
	}
	// components gives nodes in topological order
	return components;
}
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n + 1);
	for(int i = 0 ; i < m; ++i){
		int u, v;
		cin >> u >> v ;
		graph[u].push_back(v);
	}
	vector<vector<int> > components = get_components(graph);
	for(auto c : components){
		for(auto node : c){
			cerr << node << ' ';
		}
		cerr << '\n';
	}
}