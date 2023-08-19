#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
void dfs(int u, vector<vector<pair<int, int> > >& graph, vector<bool>& vis, vector<int>& top_sorted)
{
	if(vis[u])
		return ;
	vis[u] = 1;
	for(auto e : graph[u]){
		int v, wt;
		tie(v, wt) = e;
		dfs(v, graph, vis, top_sorted);
	}
	top_sorted.push_back(u);
}
vector<int> extended_dijkstras(vector<vector<pair<int, int> > >& graph){
	int n = graph.size();
	vector<vector<pair<int, int> > > dag(n), link(n);
	set<pair<int, int> > s;
	vector<int> dist(n, INF);
	dist[1] = 0;
	for(int i = 1; i < n; ++i){
		s.insert({dist[i], i});
	}
	while(s.size()){
		int u = (*s.begin()).second;
		s.erase(s.begin());
		for(auto e : graph[u]){
			int v, wt;
			tie(v, wt) = e;
			if(dist[v] >= dist[u] + wt){
				link[u].push_back({v, wt});

				s.erase({dist[v], v});
				dist[v] = dist[u] + wt;
				s.insert({dist[v], v});
			}
		}
	}
	for(int i = 1; i < n; ++i){
		for(auto e : link[i]){
			int v, wt;
			tie(v, wt) = e;
			if(dist[v] == dist[i] + wt){
				dag[i].push_back({v, wt});
			}
		}
	}
	vector<int> dp(n);
	dp[1] = 1;
	vector<bool> vis(n);
	vector<int> top_sorted;
	for(int i = 1; i < n; ++i){
		dfs(i, dag, vis, top_sorted);
	}
	reverse(top_sorted.begin(), top_sorted.end());

	for(auto u : top_sorted){
		for(auto e : dag[u]){
			int v, wt;
			tie(v, wt) = e;
			dp[v] += dp[u];
		}
	}
	return dp;
}
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int> > > graph(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	vector<int> paths = extended_dijkstras(graph);
	for(int i = 1; i < n + 1; ++i){
		cerr << paths[i] << ' ' ;
	}
	cerr << '\n';
}