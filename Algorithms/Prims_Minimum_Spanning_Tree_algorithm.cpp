#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > PrimsMST(int n, vector<vector<pair<int, int> > >& graph){
	// graph -> {{{node, weight}}}
	// Returns a vector of pair<int, int> that contains all edges in the Minimum Spanning Tree
	vector<pair<int, int> > tree;
	vector<bool> vis(n + 1);
	vis[1] = 1;
	set<tuple<int, int, int> > edges;
	for(auto e : graph[1]){
		edges.insert({e.second, e.first, 1});
	}
	while(edges.size()){
		int cost, u, v;
		tie(cost, u, v) = *edges.begin();
		edges.erase(edges.begin());
		if(vis[u])
			continue ;
		tree.push_back({u, v});
		vis[u] = 1;
		for(auto e : graph[u]){
			int node, weight;
			tie(node, weight) = e;
			if(!vis[node]){
				edges.insert({weight, node, u});
			}
		}
	}
	return tree;
}
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int> > > graph(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v, x;
		cin >> u >> v >> x;
		graph[u].push_back({v, x});
		graph[v].push_back({u, x});
	}
	vector<pair<int, int> > tree = PrimsMST(n, graph);
	for(auto c : tree){
		cout << c.first << ' ' << c.second << '\n';
	}
}