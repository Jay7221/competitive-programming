#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll> > dp;
vector<vector<pair<ll, ll> > > graph;
const ll INF = 1e15 + 7;
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	dp.resize(n + 2, vector<ll>(k + 1, INF));
	dist.resize(n + 2, INF);
	graph.resize(n + 2);
	for(int i = 1; i <= m; ++i){
		ll u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	dist[1] = 0;
	set<pair<ll, ll> > s;
	for(int i = 1; i <= n; ++i){
		s.insert({dist[i], i});
	}
	while(s.size()){
		ll u, x;
		tie(x, u) = *s.begin();
		s.erase(s.begin());
		for(auto p : graph[u]){
			ll v, w;
			tie(v, w) = p;
			if(dist[u] + w < dist[v]){
				s.erase({dist[v], v});
				dist[v] = dist[u] + w;
				s.insert({dist[v], v});
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		dp[i][0] = dist[i];
	}
	for(int i = 1; i <= n; ++i)
		cout << dist[i] << ' ' ;
	cout << '\n';
}