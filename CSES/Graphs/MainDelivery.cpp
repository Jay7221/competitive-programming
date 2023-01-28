#include<bits/stdc++.h>
using namespace std;
vector<set<int>> graph;
vector<int> deg, path;
map<pair<int, int>, bool> dp;
bool is_visited(int u, int v){
	return (dp[{u, v}] | dp[{v, u}]);
}
void visit(int u, int v){
	dp[{u, v}] = true;
}
void dfs(int u){
	set<int> tmp;
	for(auto v : graph[u]){
		tmp.insert(v * -1);
	}
	for(auto v : tmp){
		v *= -1;
		if(is_visited(u, v))
			continue;
		else
			visit(u, v);
		dfs(v);
	}
		path.push_back(u);
}
int main(){
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	deg.resize(n);
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		--a, --b;
		graph[a].insert(b);
		graph[b].insert(a);
		++deg[a];
		++deg[b];
	}
	for(int i = 0; i < n; ++i){
		if(deg[i] % 2){
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	stack<int> st;
	st.push(0);
	while(st.size()){
		int v = st.top();
		if(graph[v].size() == 0){
			st.pop();
			path.push_back(v);
		}else{
			int u = *(--graph[v].end());
			graph[u].erase(v);
			graph[v].erase(u);
			st.push(u);
		}
	}
	reverse(path.begin(), path.end());
	for(int i = 0; i < n; ++i){
		if(graph[i].size()){
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	for(auto elem : path)
		cout << elem + 1 << ' ' ;
	return 0;
}
