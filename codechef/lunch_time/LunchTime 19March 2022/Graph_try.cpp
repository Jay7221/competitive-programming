#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define debug(a, n) for(int i = 0;i < n ;i++){cerr << a[i] << ' ';} cerr << '\n';
void print_tree(map<int, vi> tree){
	for(auto c : tree){
		cerr << c.first << " : ";
		for(auto k : c.second){
			cerr << k << ' ';
		}
		cerr << '\n';
	}
}
vi bfs(map<int, vi> tree, int source, int n){
	vi dist(n + 1, 0);
	queue<int> q;
	q.push(source);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(auto child : tree[cur]){
			dist[child] = dist[cur] + 1;
			q.push(child);
		}
	}
	return dist;
}
void dfs(map<int, vi> tree, vi& count, int cur){
	count[cur] = 1;
	for(auto c : tree[cur]){
		dfs(tree, count, c);
		count[cur] += count[c];
	}
}
int main(){
	int n;
	cin >> n;
	map<int, vi> tree;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
	}
	// print_tree(tree);
	vi dist = bfs(tree, 1, n);
	// debug(dist,dist.size())
	vi count(n + 1);
	dfs(tree, count, 1);
	debug(count, count.size())
}