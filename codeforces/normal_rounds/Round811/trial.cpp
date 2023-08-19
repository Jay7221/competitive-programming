#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	vector<vector<pair<int, int> > > graph(n + 1);
	int e, t;
	cin >> e >> t;
	int m;
	cin >> m;
	while(m--){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({v, c});
	}
	vector<int> dist(n + 1, inf);
	set<pair<int, int> > s;
	dist[e] = 0;
	for(int i = 1; i < n + 1; ++i){
		s.insert({dist[i], i});
	}
	while(s.size()){
		int u, d;
		tie(d, u) = *s.begin();
		s.erase(s.begin());
		if(d == inf){
			break ;
		}
		for(auto p : graph[u]){
			int v, cost ;
			tie(v, cost) = p;
			if(dist[v] > dist[u] + cost){
				s.erase({dist[v], v});
				dist[v] = dist[u] + cost;
				s.insert({dist[v], v});
			}
		}
	}
	int ans = 0;
	for(int i = 1; i < n + 1; ++i){
		if(dist[i] <= t){
			++ans;
		}
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}