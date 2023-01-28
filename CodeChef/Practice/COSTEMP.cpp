#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<vector<int> > tree;
vector<int> cost;			// the total cost from all nodes to the ith node
vector<int> parent;		// parent of the ith node
vector<int> no_nodes;		// the number of nodes below the ith node and including itself
void dfs(int cur){
	int par = parent[cur];
	for(auto child : tree[cur]){
		if(child == par)
			continue ;
		parent[child] = cur;
		dfs(child);
		no_nodes[cur] += no_nodes[child];
		cost[cur] += cost[child] + no_nodes[child];
	}
}
void bfs(int root){
	queue<int> processed;
	processed.push(root);
	while(!processed.empty()){
		int cur = processed.front();
		processed.pop();
		for(auto child : tree[cur]){
			if(child == parent[cur])
				continue; 
			cost[child] += cost[cur] - (cost[child] + no_nodes[child]) + (n - no_nodes[child]);
			processed.push(child);
		}
	}
}
void solve(){
	cin >> n;
	tree.clear();
	tree.resize(n);
	parent.resize(n, -1);
	no_nodes.resize(n, 1);
	cost.resize(n, 0);
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		// cerr << u << ' ' << v << '\n';
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(0);
	bfs(0);
	for(int i = 0; i < n; i++){
		cout << cost[i] << ' ' ;
	}
	cout << '\n';
}
int main(){
	int t;
	t = 1;
	while(t--){
	solve();
	}
}