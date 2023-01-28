#include<bits/stdc++.h>
using namespace std;
class DSU{
	int n;
	vector<int> link, size;
	public:
		DSU(int sz);
		int find(int a);
		bool same(int a, int b);
		void merge(int a, int b);
};
DSU :: DSU(int sz){
	n = sz;
	link.resize(n + 1);
	size.resize(n + 1);
	for(int i = 0; i < n + 1; ++i){
		link[i] = i;
		size[i] = 1;
	}
}
int DSU :: find(int a){
	while(a != link[a]){
		a = link[a];
	}
	return a;
}
bool DSU :: same(int a, int b){
	return find(a) == find(b);
}
void DSU :: merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b)
		return;
	if(size[a] < size[b])
		swap(a, b);
	size[a] += size[b];
	link[b] = a;
}
vector<pair<int, int> > KruskalsMST(int n, vector<tuple<int, int, int> >& edges){
	// n -> number of nodes in the graph
	// edges -> {{weight, node1, node2}}
	// Returns a vector of pair<int, int> that contains all edges in the Minimum Spanning Tree
	sort(edges.begin(), edges.end());
	vector<pair<int, int> > tree;
	DSU d(n);
	for(auto e : edges){
		int cost, u, v;
		tie(cost, u, v) = e;
		cerr << u << ' ' << v << ' ' << cost << '\n';
		if(d.same(u, v)){
			continue ; 
		}
		else{
			d.merge(u, v);
			tree.push_back({u, v});
		}
	}
	return tree;
}
int main(){
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int> > edges;
	for(int i = 0; i < m; ++i){
		int u, v, cost;
		cin >> u >> v >> cost;
		edges.push_back({cost, u, v});
	}
	vector<pair<int, int> > tree = KruskalsMST(n, edges);
	for(auto c : tree){
		cout << c.first << ' ' << c.second << '\n';
	}
}