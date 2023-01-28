#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int> > graph;
vector<int> visited;
vector<int> parent;
vector<int> proc;
int start_n, end_n;
bool dfs(int u, int p){
	parent[u] = p;
	visited[u] = 1;
	proc[u] = 1;
	for(auto c : graph[u]){
		if(c == parent[u]){
			continue ;
		}
		if(visited[c]){
			start_n = c;
			end_n = u;
			return 1;
		}
		if(dfs(c, u)){
			return 1;
		}
	}
	return 0;
}
void print(){
	stack<int> ans;
	ans.push(start_n);
	int u = end_n;
	while(u != start_n){
		ans.push(u);
		u = parent[u];
	}
	ans.push(u);
	cout << ans.size() << '\n';
	while(!ans.empty()){
		cout << ans.top() << ' ' ;
		ans.pop();
	}
}
void solve(){
	cin >> n >> m;
	graph.resize(n + 1);
	visited.resize(n + 1);
	parent.resize(n + 1);
	proc.resize(n + 1);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i < n + 1; i++){
		if(!proc[i]){
			if(dfs(i, -1)){
				print();
				return ;
			}
		}
	}
	cout << "IMPOSSIBLE";

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}