#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> d(n + 1), dist(n + 1, m);
	vector<vector<int> > graph(n + 1);
	vector<bool> mark(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		graph[v].push_back(u);
		++d[u];
	}
	dist[n] = 0;
	set<pair<int, int> > s;
	s.insert({dist[n], n});
	while(s.size()){
		int u, k;
		tie(k, u) = *s.begin();
		s.erase(s.begin());
		if(mark[u])
			continue ;
		mark[u] = 1;
		for(auto v : graph[u]){
			if(dist[v] > dist[u] + d[v]){
				dist[v] = dist[u] + d[v];
				s.insert({dist[v], v});
			}
			--d[v];
		}
	}
	cout << dist[1] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}