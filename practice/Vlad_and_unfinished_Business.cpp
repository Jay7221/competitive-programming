#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
vector<vector<int> > graph;
vector<bool> todo, good;
void dfs(int v, int p = -1){
	for(auto c : graph[v]){
		if(c == p){
			continue;
		}
		dfs(c, v);
		if(good[c]){
			good[v] = 1;
		}
		if(todo[c]){
			todo[v] = 1;
		}
	}
}
void solve(){
	int n, k;
	cin >> n >> k;
	graph.clear();
	graph.resize(n);
	todo.resize(n), good.resize(n);
	fill(todo.begin(), todo.end(), 0);
	fill(good.begin(), good.end(), 0);
	int x, y;
	cin >> x >> y;
	x--, y--;
	good[y] = 1;
	for(int i = 0; i < k; i++){
		int v;
		cin >> v;
		v--;
		todo[v] = 1;
	}
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(x);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(i == x){
			continue ;
		}
		if(good[i]){
			ans += 1;
		}else if(todo[i]){
			ans += 2;
		}
	}
	cout << ans << '\n';
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