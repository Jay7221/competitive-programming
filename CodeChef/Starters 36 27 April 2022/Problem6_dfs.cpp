#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int> > graph;
vector<bool> visited, marked;
bool dfs(int v){
	if(marked[v]){
		return 1;
	}
	if(visited[v]){
		return 0;
	}
	// cerr << v << " : " ;
	// for(auto c : graph[v])
	// 	cerr << c << ' ' ;
	// cerr << '\n';
	visited[v] = 1;
	bool ans = 1;
	for(auto c : graph[v]){
		if(marked[c])
			continue ;
		if(visited[c]){
			return 0;
		}
		ans = ans & dfs(c);
	}
	visited[v] = 0;
	if(ans)
		marked[v] = 1;
	return ans;
}
void solve(){
	cin >> n >> m;
	graph.clear(), visited.clear(), marked.clear();
	graph.resize(n), visited.resize(n, 0), marked.resize(n, 0);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		graph[a].push_back(b);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += graph[i].empty();
		if(!dfs(i)){
			cout << -1 << '\n';
			return ;
		}
	}
	// dfs(0);
	cout << ans - 1 << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}