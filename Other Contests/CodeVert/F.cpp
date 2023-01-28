#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > graph;
vector<set<int>* > events;
vector<int> dp;
void dfs(int u, int par = -1){
	auto merge = [&](set<int> *a, set<int> *b){
		if((*a).size() < (*b).size()){
			swap(a, b);
		}
		for(auto elem : (*b)){
			(*a).insert(elem);
		}
		return a;
	};
	set<int> *cur = events[u];
	for(auto child : graph[u]){
		if(child == par){
			continue ;
		}
		dfs(child, u);
		cur = merge(cur, events[child]);
	}
	dp[u] = (*cur).size();
	events[u] = cur;
}
int main() {
	cin >> n;
	graph.resize(n);
	events.resize(n);
	dp.resize(n);
	for(int i = 0; i < n; ++i){
		int c;
		cin >> c;
		events[i] = new set<int> ;
		(*events[i]).insert(c);
	}
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0);
	for(int i = 0; i < n; ++i){
		cout << dp[i] << ' ';
	}
	return 0;
}